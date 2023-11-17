#include <iostream>
#include <iomanip>

// Function prototypes
int getNumDays();
void getTimeOfDay(int& departureHour, int& departureMinute, int& arrivalHour, int& arrivalMinute);
double getRoundTripAirfare();
double getCarRentals();
double getMilesDriven();
double getParkingFees(int numDays);
double getTaxiFees(int numDays);
double getConferenceFees();
double getHotelExpenses(int numDays);
double getMealsExpenses(int numDays, int departureHour, int arrivalHour);

double calculateTotalExpenses(double roundTripAirfare, double carRentals, double milesDriven,
                               double parkingFees, double taxiFees, double conferenceFees,
                               double hotelExpenses, double mealsExpenses);

double calculateTotalAllowableExpenses(int numDays);

void displayResults(double totalExpenses, double totalAllowableExpenses);

int main() {
    int numDays;
    int departureHour, departureMinute, arrivalHour, arrivalMinute;
    double roundTripAirfare, carRentals, milesDriven, parkingFees, taxiFees, conferenceFees, hotelExpenses, mealsExpenses;

    // Get input
    numDays = getNumDays();
    getTimeOfDay(departureHour, departureMinute, arrivalHour, arrivalMinute);
    roundTripAirfare = getRoundTripAirfare();
    carRentals = getCarRentals();
    milesDriven = getMilesDriven();
    parkingFees = getParkingFees(numDays);
    taxiFees = getTaxiFees(numDays);
    conferenceFees = getConferenceFees();
    hotelExpenses = getHotelExpenses(numDays);
    mealsExpenses = getMealsExpenses(numDays, departureHour, arrivalHour);

    // Calculate and display results
    double totalExpenses = calculateTotalExpenses(roundTripAirfare, carRentals, milesDriven,
                                                   parkingFees, taxiFees, conferenceFees,
                                                   hotelExpenses, mealsExpenses);

    double totalAllowableExpenses = calculateTotalAllowableExpenses(numDays);

    displayResults(totalExpenses, totalAllowableExpenses);

    return 0;
}