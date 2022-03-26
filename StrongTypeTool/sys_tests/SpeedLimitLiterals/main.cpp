#include <cassert>

#include "StrongTypes/Speed.h"
#include "StrongTypes/StrongLiterals.h"

// Speed limit in km
const Speed MAX_SPEED_LIMIT = 90_kmh;
const Speed MIN_SPEED_LIMIT = 20_kmh;

bool checkIfAllowed(Speed speed) {
    return MIN_SPEED_LIMIT <= speed
           && MAX_SPEED_LIMIT >= speed;
}

int main() {

    assert(checkIfAllowed(60_kmh));
    assert(!checkIfAllowed(170_kmh));

    Speed validSpeed = 60_kmh;
    assert(checkIfAllowed(validSpeed));

    return 0;
}
