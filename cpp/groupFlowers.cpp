/*
n flowers
color of ith flower is a[i] , a[i] is int
pick some of all flowers, divide into 2 groups
first group should ahve flowers of smae color,
second group should have flowers of different colors

size of first = size of second
return size, if multiple solution and return max size


1,1,2,3

1,1 - 2,3

3
color, number
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int maxDefinedSize(vector<int> flowers) {
    unordered_map<int,int> flowersFreq;

    for(int i=0; i<flowers.size(); i++) {
        flowersFreq[flowers[i]]++;
    }

    int maxPossible = flowersFreq.size();
    int res = 0;
    int maxOccuringFlower;
    for(auto itr = flowersFreq.begin(); itr != flowersFreq.end(); itr++) {
        if(res < itr->second) {
            res = itr -> second;
            maxOccuringFlower = itr->first;
        }
    }

    if(maxOccuringFlower == maxPossible) {
        return maxPossible-1;
    }

    return min(maxPossible, res);
}

int main() {
   vector<int> flowers = {1,1,2,3};
   cout << maxDefinedSize(flowers) << endl;

   flowers = {1,1,1,2};
   cout << maxDefinedSize(flowers) << endl;

   flowers = {1,1,2,2};
   cout << maxDefinedSize(flowers) << endl;
   return 0;
}