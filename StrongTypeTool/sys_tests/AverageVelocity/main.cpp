#include <iostream>
#include <vector>
#include "StrongTypes/Distance.h"

Speed calculateAverageSpeed(std::vector<std::pair<Distance,Time>> data) {
    Distance distanceSum = Distance(0.0);
    Time timeSum = Time(0.0);
    for(std::pair<Distance, Time> entry : data) {
        distanceSum += entry.first;
        timeSum += entry.second;
    }
    return distanceSum / timeSum;
}

int main() {
    std::cout << calculateAverageSpeed(
             {{Distance(60.0),Time(1.0)},
              {Distance(100.0),Time(2.0)}}).get() << std::endl;

    return 0;
}