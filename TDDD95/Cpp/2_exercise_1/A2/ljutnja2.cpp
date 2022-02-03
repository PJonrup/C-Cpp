

#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::flush, std::ios_base, std::sort;

// #define ANGER(x) ((x)*(x) - (x-1)*(x-1))

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    unsigned long long *arr = new unsigned long long[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // arr = beginning of array, arr + n = length of the array we want to sort.
    sort(arr, arr+n);

    // std::sort(std::begin(arr), std::end(arr), std::greater<>());
    // std::sort(std::begin(arr), std::end(arr), std::greater<int>());  // <int> needed before C++14.

    // Binary Search for the opt (optimal) value to look for anger.
    int low = 0, high = arr[n-1], opt;

    // minimum candies missing.
    while (low != high) {
        
        opt = (low + high + 1) / 2;
        
        unsigned long long sum = 0;
        
        for (int i = 0; i < n; i++) {

            if (arr[i] > opt) {
                sum += arr[i] - opt;
            }
            else {
                sum += 0;
            }
        }
        if (sum < m) {
            high = opt - 1;
            
        }
        else {
            low = opt;
        }
    }

    // Check level 1 higher than opt.
    opt = low + 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > opt) {
            m -= arr[i] - opt;
            arr[i] = opt;
        }
    }

    // Check level of optimum.
    opt--;

    for (int i = 0; i < n && m > 0; i++) {
        if (arr[i] > opt) {
            arr[i]--;
            m--;
        }
    }

    // Calculates the sum of anger from an array with the cut down amount of anger from children.
    unsigned long long sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += arr[i] * arr[i];
    }

    cout << sum2 << '\n';
    delete [] arr;
    
    return 0;
}