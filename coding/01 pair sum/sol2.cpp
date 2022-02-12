#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();

    // Map to store frequency of elements.
    map<int, int> hash;

    // This will store the result.
    vector<vector<int>> ans;

    for (int ele : arr) {
        int count = hash[s - ele];

        vector<int> pair(2);
        pair[0] = ele;
        pair[1] = s - ele;

        while (count--)
            ans.push_back(pair);

        hash[ele] += 1;
    }

    // This will store the final result.
    vector<vector<int>> res(ans.size(), vector<int>(2, 0));

    // Sorting the 'ans' arrays element.
    for (int i = 0; i < ans.size(); i++) {
        int a = ans[i][0], b = ans[i][1];
        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }

    // Finally sorting each pair in 'res'.
    sort(res.begin(), res.end());
    return res;
}

int main() {

   vector<int> arr = {10,20,30,40,50};
   vector<vector<int>> res = pairSum(arr,50);

   for(vector<int> v : res){
       for(int i : v)
            cout << i << " ";
        cout << endl;
   }

   return 0;
}