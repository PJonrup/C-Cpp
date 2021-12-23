#include <iomanip>
#include <iostream>

using std::cout, std::cin, std::endl;

/*
Print a tax (VAT) table.

User input:
1. lower and upper price limit.
2. a length for each step in the talbe (stride).
3. Tax percentage (between 0-100%)

User will only input FLOAT values within [-100.00, +100000.00] 
and not more than 2 decimals.

Error handling:
You can only use INT and FLOAT to check type errors.

*/

int main() {

    float fprice{}, lprice{}, stride{}, tax{};


    // Input
    cout << "INPUT PART\n";
    cout << "==========\n";

    cout << "Enter first price: ";
    cin >> fprice;
    cout << "Enter last price: ";
    cin >> lprice;
    cout << "Enter stride: ";
    cin >> stride;
    cout << "Enter tac percent: ";
    cin >> tax;
    cout << endl;

    // Tax Table
    cout << "TAX TABLE\n";
    cout << "=========\n";

    


    return 0;
}