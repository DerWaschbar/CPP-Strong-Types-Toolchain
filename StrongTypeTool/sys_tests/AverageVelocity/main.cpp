#include <iostream>
#include <vector>
#include "StrongTypes/Distance.h"

namespace example {

    Velocity calculateAverageVelocity(std::vector<std::pair<Distance,Time>> data) {
        Velocity velocitySum = Velocity(0.0);
        for(std::pair<Distance, Time> entry : data) {
            velocitySum += entry.first / entry.second;
        }
        return velocitySum / (float) data.size();
    }

}

int main() {
    std::cout << example::calculateAverageVelocity(
            {{Distance(60.0),Time(1.0)},
             {Distance(100.0),Time(2.0)}}).get() << std::endl;

    return 0;
}