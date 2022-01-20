

#include <iostream>
#include <set>

using std::cout, std::cin, std::flush, std::set, std::ios_base;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        int a;
        int count = 0;
        set<int> cd;

        for (int i = 0; i < n; i++) {
            cin >> a;
            cd.insert(a);
        }
        for (int i = 0; i < m; i++) {
            cin >> a;
            if (cd.count(a) == 1) {
                count++;
            }
            
        }

        cout << count << '\n';
    }

    return 0;
}