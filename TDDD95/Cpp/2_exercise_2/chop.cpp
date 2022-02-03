#include <iostream>
#include <algorithm>
#include <unordered_map>
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

    // Get the input.
    unsigned int *arr = new unsigned int[n];
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Set up v in an unordered map (reversed as map adds elements to the front)
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == last) {
            err = false;
        }

        if (umap.count(arr[i]) >= 1) {
            umap[arr[i]]++;
        }
        else {
            umap[arr[i]] = 1;
        }
    }   

    // Check so that we have found the last node in v.
    if (err == true) {
        cout << "Error" << endl;
        return 0;
    }

    // Get all elements that are leafs (leaf-nodes).
    set<int> leafs;

    for (int i = 0; i < n; i++) {
        if (umap.count(i + 1) == 0) {
            leafs.insert(i + 1);
        }
    }

    // Loops though n (v).
    for (int i = 0; i < n; i++) {
        // Loops through second element of map and prints leaf-nodes.
        for (int j = 0; j < umap.begin()->second; j++) {
            //cout << *(leafs.begin()) << '\n';
            cout << *(leafs.begin()) << endl;
            leafs.erase(*(leafs.begin()));
            // Checks if we are on the last iteration of the second element of the map,
            // removes it from the map and adds it to leafs (leaf-nodes).
            if (j + 1 == umap.begin()->second) {
                leafs.insert(umap.begin()->first);
                umap.erase(umap.begin());
                break; 
            }
        }
    }

    delete [] arr;
    
    return 0;
}