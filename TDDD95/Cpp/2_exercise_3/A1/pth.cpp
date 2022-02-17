
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //unsigned long n;    // I do not know if - values are okay so try this first.
    long n;     // 32-bit integer
    double x;
    int p;

    // The loop takes inputs intil 0 is reached which is interpreted as false.
    while (cin >> n && n) {
        
        // Used to check for negative values, 0 would be caught in while loop.
        bool negative = false;
        
        if (n < 0) {
            n = -n;
            negative = true;
        }
        
        // A 2-bit value ^2 (or left-shifted) becomes a 4-bit value,
        // therefore we can check p (32-bit) against its input by n^(1 / p)
        // and check this value and its floor/ceil distances to check if it
        // is close to zero. This is done as there can be small double roundings 
        // that does not become 0.0 and instead become 0.9..9 or 0.0..1
        for (p = 31; p >= 1; p--) {
            x = pow(n, 1.0/p);
            if (x - floor(x) < 0.001) {
                if (pow(floor(x), p) == n) {    // some values within 0.001 can still be wrong, therefore we check this here.
                    if (!negative || p%2) {     // if the value was negative, check so that it has an uneven exponent so that it becomes positive.
                        cout << p << endl;
                        break;
                    }
                }
            }
            else if (ceil(x) - x < 0.001) {
                if (pow(ceil(x), p) == n) {
                    if (!negative || p%2) {
                        cout << p << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}