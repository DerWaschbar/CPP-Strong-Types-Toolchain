#include <cassert>

#include "StrongTypes/Speed.h"

// Speed limit in km
const Speed MAX_SPEED_LIMIT = Speed(90);
const Speed MIN_SPEED_LIMIT = Speed(20);

bool checkIfAllowed(Speed speed) { return MIN_SPEED_LIMIT <= speed && MAX_SPEED_LIMIT >= speed; }

int main() {

    assert(checkIfAllowed(Speed(60)));
    assert(!checkIfAllowed(Speed(170)));

    Speed validSpeed = Speed(60);
    assert(checkIfAllowed(validSpeed));

    return 0;
}