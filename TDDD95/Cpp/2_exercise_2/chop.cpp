#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // try to use map and set how many vectors one node is supposed to have connected to it.
    // if you can not find the n+1 node in v (input) then there should be an "Error" printed.
    unsigned int n;
    cin >> n;
    int last = n+1;
    bool err = true;

    // Get the input set up v in an map.
    unsigned int *arr = new unsigned int[n];
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] == last) {   // this does not need to be here, if n+1 is last then it is okay, otherwise not.
            err = false;
        }

        if (mp.count(arr[i]) >= 1) {
            mp[arr[i]] += 1;
        }
        else {
            mp[arr[i]] = 1;
        }
    }

    // Check so that we have found the last node in v.
    if (err == true) {
        cout << "Error\n";
        return 0;
    }

    // Get all elements that are leafs (leaf-nodes).
    set<int> leafs;

    for (int i = 0; i < n; i++) {
        if (mp.count(i + 1) == 0) {
            leafs.insert(i + 1);
        }
    }

    // Loops though n (v).
    for (int i = 0; i < n; i++) {
        if (mp[arr[i]] > 0) {
            cout << *(leafs.begin()) << endl;
            leafs.erase(*leafs.begin());
            mp[arr[i]]--;
            if (mp[arr[i]] == 0) {
                leafs.insert(arr[i]);
                mp.erase(mp[arr[i]]);
            }
        }
    }

    delete [] arr;
    
    return 0;
}