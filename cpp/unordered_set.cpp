#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print(unordered_set<int> s) {
    // printing set s1
    unordered_set<int>::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main() {
    // initialize
    //1. Initializing by pushing values one by one :
    unordered_set <int> s1;

    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    // only one 50 will be added to the set
    s1.insert(50);
    s1.insert(10);

    print(s1);

    //  find returns end iterator if key is not found,
    //  else it returns iterator to that key
    int key = 1 ;
    if (s1.find(key) == s1.end())
        cout << key << " not found" << endl << endl ;
    else
        cout << "Found " << key << endl << endl ;

    // assigning the elements from s1 to s2
    unordered_set<int> s2(s1.begin(), s1.end());
    print(s2);

    // remove all elements up to 30 in s2
    cout << "\ns2 after removal of elements less than 30 \n";
    s2.erase(s2.begin(), s2.find(30));
    print(s2);

    // remove element with value 50 in s2
    int num;
    num = s2.erase(50);
    cout << "\ns2.erase(50) : " << num << " removed\n";
    print(s2);

    return 0;
}