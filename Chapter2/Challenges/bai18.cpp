#include <iostream>
using namespace std;

int main() {
    int totalCustomers = 16500;
    double percentEnergyDrinkBuyers = 0.15;
    double percentCitrusFlavored = 0.58;

    // Calculate the approximate number of customers who purchase energy drinks per week
    int energyDrinkBuyers = totalCustomers * percentEnergyDrinkBuyers;

    // Calculate the approximate number of customers who prefer citrus-flavored energy drinks
    int citrusFlavoredBuyers = energyDrinkBuyers * percentCitrusFlavored;

    // Display the results
    cout << "Approximate number of customers who purchase energy drinks per week: " << energyDrinkBuyers << endl;
    cout << "Approximate number of customers who prefer citrus-flavored energy drinks: " << citrusFlavoredBuyers << endl;

    return 0;
}
