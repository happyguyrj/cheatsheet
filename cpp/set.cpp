#include <bits/stdc++.h>
#include <iostream>

using namespace std;


void printGSet(set<int, greater<int>> s) {
    // printing set s1
    set<int, greater<int> >::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}


void print(set<int> s) {
    // printing set s1
    set<int>::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main() {
    // initialize
    //1. Initializing by pushing values one by one :
    set <int, greater<int> > s1;

    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    // only one 50 will be added to the set
    s1.insert(50);
    s1.insert(10);

    printGSet(s1);

    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());
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

    // lower bound and upper bound for set s1
    cout << "s1.lower_bound(40) : " << *s1.lower_bound(40) << endl;
    cout << "s1.upper_bound(40) : " << *s1.upper_bound(40) << endl;

    // lower bound and upper bound for set s2
    cout << "s2.lower_bound(40) : " << *s2.lower_bound(40) << endl;
    cout << "s2.upper_bound(40) : " << *s2.upper_bound(40) << endl;

    return 0;
}