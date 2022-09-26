#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QCoreApplication>
#include <QPushButton>
#include <cmath>
#include <iostream>
#include <QLabel>
#include <QtAlgorithms>

#include "game.h"
#include "mainwindow.h"
#include "hexacell.h"
#include "point.hpp"

namespace abalone { namespace view {

MainWindow::MainWindow(model::Game * subject, QWidget * parent)
    : QMainWindow(parent),
      subject_ {subject},
      move_{}
{
    scene_ = new QGraphicsScene();
    double rad = 40;
    double w = sqrt(3) / 2 * rad;

    for (auto z = 0; z < subject_->getBoard().size(); z++) {
        for (auto y = 0; y < subject_->getBoard().size(); y++) {
            for (auto x = 0; x < subject_->getBoard().size(); x++) {
                abalone::model::Position position = abalone::model::Position(x,y,z);
                if (subject_->getBoard().isPosPossible(position)) {
                    HexaCell * hexa =new HexaCell(position,rad, (x*2*w)+(z*w), z*(1.5*rad), nullptr);
                    hexa->registerObserver(this);
                    board_.append(hexa);
                    scene_->addItem(hexa);
                }
            }
        }
    }


    drawInfo();

    view_ = new QGraphicsView(scene_);
    view_->setRenderHint(QPainter::Antialiasing);
    view_->setRenderHint(QPainter::TextAntialiasing);
    view_->setCacheMode(QGraphicsView::CacheBackground);
    view_->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view_->setDragMode(QGraphicsView::ScrollHandDrag);
    view_->update();
    this->setCentralWidget(view_);

    setWindowTitle("Abalone");
    subject_->registerObserver(this);
    update(subject);
    resize(1000,800);
}

QString MainWindow::printWin() {
    if (subject_->playerBlack().nbMarbles() == 8) {
        return "Congrats ! Player white won!!";
    } else {
        return "Congrats ! Player black won!!" ;
    }
}

MainWindow::~MainWindow()
{

}

void MainWindow::restart() {
    subject_->reset();
}

void MainWindow::makeMove() {
    try {
        if(move_.size() == 2) {
            subject_->makeMove(move_[0],move_[1]);
            move_.clear();
        } else if(move_.size() == 3) {
            subject_->makeMove(move_[0],move_[1],move_[2]);
            move_.clear();
        } else {
            throw std::invalid_argument("Please select 2 or 3 cases !");
        }
    }   catch (const std::exception & e) {
        QMessageBox::information(this,tr("Impossible move!!"),tr(e.what()));
    }
}

void MainWindow::addPosToMove(abalone::model::Position pos){
    bool inserted = true;
    for(unsigned long i = 0; i < move_.size() && inserted;i++) {
        if (move_[i].x() == pos.x() && move_[i].y() == pos.y() &&move_[i].z() == pos.z()) {
            move_.erase (move_.begin()+i);
            inserted = false;
        }
    }
    if(inserted) {
        move_.push_back(pos);
    }
}

void MainWindow::drawInfo(){

    button_ = new QPushButton;
    const auto size_x = 200;
    const auto size_y = 50;

    button_->setGeometry(QRect(1000-size_y*5,800-size_x*1.5, size_x, size_y));
    button_->setText("Make move!");
    button_->setFont(QFont("times", 18));
    connect(button_,SIGNAL(clicked()),this,SLOT(makeMove()));
    QFont font = QFont("times", 18);

    turn_ = new QLabel();
    turn_->move(1000-size_y*5,0);
    turn_->setText("Player Turn : ");
    turn_->setFont(font);

    black_ = new QLabel();
    black_->move(1000-size_y*5,50);
    QString blackLeft = "Black Marbles : ";
    blackLeft.append(QString::number(subject_->playerBlack().nbMarbles()));
    black_->setText(blackLeft);
    black_->setFont(font);

    white_ = new QLabel();
    white_->move(1000-size_y*5,100);
    QString whiteText = "White Marbles : ";
    whiteText.append(QString::number(subject_->playerWhite().nbMarbles()));
    white_->setText(whiteText);
    white_->setFont(font);

    scene_->addWidget(button_);
    scene_->addWidget(turn_);
    scene_->addWidget(black_);
    scene_->addWidget(white_);
}

void MainWindow::showMenu() {
    QMessageBox msgBox;
    msgBox.setText(printWin());
    msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Reset);
    msgBox.setDefaultButton(QMessageBox::Close);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Close:
        close();
        break;
    case QMessageBox::Reset:
        restart();
        break;
    }
}

void MainWindow::update(const Observable * subject) {
    if (subject == subject_) {
        if(subject_->checkWon()) {
            showMenu();
        } else {

            double rad = 40;
            double w = sqrt(3) / 2 * rad;

            for(auto i = 0; i < board_.size();i++){
                board_.at(i)->init();
            }

            for(auto i = 0; i < marbles_.size();i++){
                marbles_.at(i)->hide();
            }

            for (auto z = 0; z < subject_->getBoard().size(); z++) {
                for (auto y = 0; y < subject_->getBoard().size(); y++) {
                    for (auto x = 0; x < subject_->getBoard().size(); x++) {
                        abalone::model::Position position = abalone::model::Position(x,y,z);
                        if (subject_->getBoard().isPosPossible(position)) {
                            if (subject_->getBoard().playerAtPosition(position)) {
                                QPen pen(Qt::black, 2);
                                QBrush brush;
                                if(subject_->getBoard().playerAtPosition(position)->id() == 1) {
                                    brush.setColor(Qt::black);
                                } else {
                                    brush.setColor(Qt::white);
                                }
                                brush.setStyle(Qt::SolidPattern);
                                QGraphicsEllipseItem * ellipse =new QGraphicsEllipseItem((x*2*w)+(z*w) - w/2, z*(1.5*rad) -w/2,w,w,nullptr);
                                ellipse->setBrush(brush);
                                ellipse->setPen(pen);
                                marbles_.push_back(ellipse);
                                scene_->addItem(ellipse);
                            }
                        }
                    }
                }
            }
            QPen pen(Qt::black, 2);
            QBrush brush;
            if(subject_->playerTurn()->id() == 1) {
                brush.setColor(Qt::black);
            } else {
                brush.setColor(Qt::white);
            }
            brush.setStyle(Qt::SolidPattern);
            scene_->addEllipse(1000-200+4*w,0,w,w, pen,brush);

            QString blackLeft = "Black Marbles : ";
            blackLeft.append(QString::number(subject_->playerBlack().nbMarbles()));
            black_->setText(blackLeft);

            QString whiteText = "White Marbles : ";
            whiteText.append(QString::number(subject_->playerWhite().nbMarbles()));
            white_->setText(whiteText);

        }} else {
        Observable * test = const_cast<Observable *>(subject);
        HexaCell * h = static_cast<HexaCell *>(test);
        addPosToMove(h->pos_);
    }}

}}
