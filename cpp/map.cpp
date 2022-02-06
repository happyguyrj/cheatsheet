#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    // initialize
    map<int, int> umap;

    // inserting values by using [] operator
    umap[1] = 10;
    umap[2] = 20;
    umap[3] = 30;

    // Traversing a map
    for (auto x : umap)
      cout << x.first << " " << x.second << endl;


    // inserting value by insert function
    umap.insert(make_pair(0, 2));

    int key = 4;

    // If key not found in map iterator to end is returned
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n";
    // If key found then iterator to that key is returned
    else
        cout << "Found " << key << "\n\n";

    key = 2;
    if (umap.find(key) == umap.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

    //    iterating over all value of umap
    map<int, int>:: iterator itr;
    cout << "\nAll Elements : \n";
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stores the value part
        cout << itr->first << "  " << itr->second << endl;
     }

   return 0;
}