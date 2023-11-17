#include <iostream>
using namespace std;

int main() {
    const int totalGallons = 20;
    const double townMilesPerGallon = 23.5;
    const double highwayMilesPerGallon = 28.9;

    double townDistance = totalGallons * townMilesPerGallon;
    double highwayDistance = totalGallons * highwayMilesPerGallon;

    cout << "When driven in town, the car can travel " << townDistance << " miles on one tank of gas." << endl;
    cout << "When driven on the highway, the car can travel " << highwayDistance << " miles on one tank of gas." << endl;

    return 0;
}
