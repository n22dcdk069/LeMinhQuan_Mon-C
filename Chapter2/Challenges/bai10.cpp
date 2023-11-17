#include <iostream>
using namespace std;

int main() {
    const int gallons = 15;
    const int miles = 375;

    double mpg = static_cast<double>(miles) / gallons;

    cout << "The car gets " << mpg << " miles per gallon." << endl;

    return 0;
}
