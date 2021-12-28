#include <iomanip>
#include <iostream>

using std::cout, std::cin, std::endl, std::setw, std::setfill, std::string, std::to_string, std::setprecision, std::fixed;

void print(float &, float &, float &);

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
    cout << setw(10) << setfill('=') << "\n";

    do {
        cout << "Enter first price: ";
        cin >> fprice;

        if (fprice < 0) {
            cout << "ERROR: First price myst be at least 0 (zero) SEK" << endl;
        }
    } while (fprice < 0);

    do {
        cout << "Enter last price : ";
        cin >> lprice;

        if (fprice > lprice) {
            cout << "ERROR: Last price must be greater than first price" << endl;
        }
    } while (fprice > lprice);

    do {
        cout << "Enter stride     : ";
        cin >> stride;

        if (stride <= 0) {
            cout << "ERROR: Stride must be at least 0.01" << endl;
        }
    } while (stride <= 0);

    do {
        cout << "Enter tax percent: ";
        cin >> tax;

        if (tax < 0) {
            cout << "ERROR: Tax must be at least 0 (zero) %" << endl;
        }
    } while (tax < 0);

    cout << endl;

    // Tax Table
    cout << "TAX TABLE\n";
    cout << setw(10) << setfill('=') << "\n";

    cout << "\tPrice" << "\t\tTax" << "\t\tPrice with tax" << endl;
    cout << setw(56) << setfill('-') << "\n";

    float current{fprice};    // non-destructive do-while-loop

    /*  ---------------------------     Varöfr fungerar inte det här??? ----------------------
    while (current <= lprice) {
        float tempTax = current*tax*0.01;
        float tempPrice = current + tempTax;
        print(current, tempTax, tempPrice);

        current += stride;
    }
    */

    while (current <= lprice + (stride * 0.5)) {
        float tempTax = current*tax*0.01;
        float tempPrice = current + tempTax;
        print(current, tempTax, tempPrice);

        current += stride;
    }

    cout << "\n";

    return 0;
}

void print(float & arg1, float & arg2, float & arg3) {
    cout << fixed << setprecision(2);
    cout << "\t";
    cout << arg1;
    cout << "\t\t";
    cout << arg2;
    cout << "\t\t";
    cout << arg3;
    cout << endl;
}
/*
default:
3.1416
2006
1e-010

fixed:
3.14159
2006.00000
0.00000

scientific:
3.14159e+000
2.00600e+003
1.00000e-010
*/