

#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::flush, std::ios_base, std::sort;

// #define ANGER(x) ((x)*(x) - (x-1)*(x-1))

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, sum;
    int n;
    cin >> m >> n;

    unsigned long long *arr = new unsigned long long[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    // ---------------------------------

    sort(arr, arr+n);

    int low = 0, high = arr[n-1] - 1, d;

    while (low != high) {
        d = (low + high + 1) / 2;
        unsigned long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (arr[i] > d ? arr[i] - d : 0);
        }
        if (sum < m) {
            high = d - 1;
        }
        else {
            low = d;
        }
    }

    d = low + 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > d) {
            m -= arr[i] - d;
            arr[i] = d;
        }
    }

    d--;

    for (int i = 0; i < n && m > 0; i++) {
        if (arr[i] > d) {
            arr[i]--;
            m--;
        }
    }

    unsigned long long sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += arr[i]*arr[i];
    }


    // ---------------------------------
    /*
    int diff{sum - m};
    int anger{0};
    int mult{1};
    int i{0};
    
    if (diff < m) {
        cout << diff << '\n';
    }
    else {

        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                arr[i]--;
                anger += ANGER(mult);
                diff--;
            }

            if (diff == 0) {
                mult++;
            }
        }

        // -------------------------------

        while (diff) {
            if (arr[i]) {
                arr[i]--;
                anger += ANGER(mult);
                diff--;
            }

            if (i == n - 1) {
                i = 0;
                mult++;
            }
            else {
                i++;
            }
        }

        cout << anger << '\n';

        delete [] arr;
    }
    */

    cout << sum2 << '\n';
    delete [] arr;
    
    return 0;
}