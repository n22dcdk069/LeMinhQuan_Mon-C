#include <iostream>
using namespace std;

int main() {
    // Constants
    const double widgetWeight = 12.5; // Weight of each widget in pounds

    // Variables
    double palletWeight, totalWeight;
    int numberOfWidgets;

    // Input
    cout << "Enter the weight of the pallet by itself (in pounds): ";
    cin >> palletWeight;

    cout << "Enter the total weight of the pallet with widgets (in pounds): ";
    cin >> totalWeight;

    // Calculate the number of widgets
    numberOfWidgets = static_cast<int>((totalWeight - palletWeight) / widgetWeight);

    // Display the result
    cout << "Number of widgets stacked on the pallet: " << numberOfWidgets << endl;

    return 0;
}
