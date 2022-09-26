#include "marble.h"
#include <stdexcept>

namespace abalone { namespace model {

Marble::Marble(Player & play) :
    player_ {&play}
{}

}}
