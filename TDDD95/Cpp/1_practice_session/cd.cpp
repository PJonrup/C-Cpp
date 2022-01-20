
//#include <stdio.h>  // scanf and printf are mostly faster than cin and cout.

#include <iostream>
#include <map>

using std::cout, std::cin, std::flush, std::map, std::ios_base;

/*
Flush:
cout << endl;
without the above ios:: cin and cout are tied, meaning when reading from cin cout is flushed.

INFO: Kattis help C++
ios::sync_with_stdio(false);
cin.tie(NULL);

g++ help.py < help.in | diff - help.ans
*/

int mergeArray(int arr1[], int arr2[], int n, int m) {

    map<int, bool> mp;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (mp.count(arr1[i]) == 1) {
            count++;
        }
        mp[arr1[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        if (mp.count(arr2[i]) == 1) {
            count++;
        }
        mp[arr2[i]] = true;
    }

    return count;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        int arr1[n], arr2[m], arr3[n+m];

        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        cout << mergeArray(arr1, arr2, n, m) << '\n';
    }

    cout << flush;
    return 0;
}