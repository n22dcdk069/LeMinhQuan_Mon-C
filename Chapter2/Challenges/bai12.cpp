#include <iostream>
using namespace std;

int main() {
    const int squareFeetPerAcre = 43560;
    int squareFeet = 391876;

    double acres = static_cast<double>(squareFeet) / squareFeetPerAcre;

    cout << "The tract of land is " << acres << " acres." << endl;

    return 0;
}