 // This program creates three instances of the Rectangle class.
#include <iostream>
using namespace std;

// Rectangle class declaration.
      Lines 6 through 62 have been left out.

//*****************************************************
// Function main *
//*****************************************************

int main()
{
    double number; // To hold a number
    double totalArea; // The total area
    Rectangle kitchen; // To hold kitchen dimensions
    Rectangle bedroom; // To hold bedroom dimensions
    Rectangle den; // To hold den dimensions

    // Get the kitchen dimensions.
    cout << "What is the kitchen's length? ";
    cin >> number; // Get the length
    kitchen.setLength(number); // Store in kitchen object
    cout << "What is the kitchen's width? "; 
    cin >> number; // Get the width
    kitchen.setWidth(number); // Store in kitchen object

    // Get the bedroom dimensions.
    cout << "What is the bedroom's length? ";
    cin >> number; // Get the length
    bedroom.setLength(number); // Store in bedroom object
    cout << "What is the bedroom's width? ";
    cin >> number; // Get the width
    bedroom.setWidth(number); // Store in bedroom object

    // Get the den dimensions.
    cout << "What is the den's length? ";
    cin >> number; // Get the length
    den.setLength(number); // Store in den object
    cout << "What is the den's width? ";
    cin >> number; // Get the width
    den.setWidth(number); // Store in den object
 
    // Calculate the total area of the three rooms.
    totalArea = kitchen.getArea() + bedroom.getArea() +
    den.getArea();

    // Display the total area of the three rooms.
    cout << "The total area of the three rooms is "
         << totalArea << endl;

    return 0;
} 