#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants representing ticket prices and the percentage kept by the theater
    const double ADULT_PRICE = 10.00;
    const double CHILD_PRICE = 6.00;
    const double PERCENTAGE_THEATER_KEEP = 0.2;  // 20%

    // Variables to store user input and calculated values
    string movieName;
    int adultTickets, childTickets;
    double grossProfit, netProfit, distributorAmount;

    // Get user input for movie details
    cout << "Enter the name of the movie: ";
    getline(cin, movieName);

    cout << "Enter the number of adult tickets sold: ";
    cin >> adultTickets;

    cout << "Enter the number of child tickets sold: ";
    cin >> childTickets;

    // Calculate gross and net box office profit
    grossProfit = (adultTickets * ADULT_PRICE) + (childTickets * CHILD_PRICE);
    netProfit = grossProfit * (1 - PERCENTAGE_THEATER_KEEP);
    distributorAmount = grossProfit - netProfit;

    // Display the report
    cout << fixed << setprecision(2);
    cout << "\nMovie Name: \"" << movieName << "\"" << endl;
    cout << "Adult Tickets Sold: " << adultTickets << endl;
    cout << "Child Tickets Sold: " << childTickets << endl;
    cout << "Gross Box Office Profit: $ " << grossProfit << endl;
    cout << "Net Box Office Profit: $ " << netProfit << endl;
    cout << "Amount Paid to Distributor: $ " << distributorAmount << endl;

    return 0;
}
