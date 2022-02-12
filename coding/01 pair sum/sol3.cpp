#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Used to store result.
    vector<vector<int>> ans;
    map<int, int> mp;
    vector<int> keyArray;

    for (int num : arr) {
        if(!mp.count(num))
            keyArray.push_back(num);
        mp[num] += 1;
    }

    sort(keyArray.begin(), keyArray.end());

    for (int key : keyArray)
        if (key + key == s) {
            int freq = mp[key];
            for (int j = 0; j < freq * (freq - 1) / 2; j++)
                ans.push_back({ key, key });
        }

    // Maintain two pointers.
    int low = 0;
    int high = keyArray.size() - 1;
    while (low < high) {
        int currSum = keyArray[low] + keyArray[high];
        if (currSum == s) {
            int freq = mp[keyArray[low]] * mp[keyArray[high]];
            for (int j = 0; j < freq; j++)
                ans.push_back({ keyArray[low], keyArray[high] });

            low++;
            high--;
        }
        else if (currSum < s)
            low++;
        else
            high--;
    }

    for (int i = 0; i < ans.size(); i++) {
        int a = ans[i][0], b = ans[i][1];
        ans[i][0] = min(a, b);
        ans[i][1] = max(a, b);
    }

    sort(ans.begin(), ans.end());
    return ans;
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