#include "StrongTypes/Distance.h"
#include <iostream>

Distance addDistance(Distance base, Distance additional) { return base + additional; }

int main() {

    Distance base = Distance(30);
    base = addDistance(base, Distance(10));
    std::cout << base.get();

    return 0;
}