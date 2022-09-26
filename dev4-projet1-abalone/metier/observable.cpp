#include "observable.h"

void Observable::registerObserver(Observer * observer) {
    observers_.insert(observer);
}

void Observable::notifyObservers() const {
    for (Observer * observer : observers_) {
        observer->update(this);
    }
}

void Observable::unregisterObserver(Observer * observer) {
    observers_.erase(observer);
}
