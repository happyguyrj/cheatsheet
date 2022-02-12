#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/*
Suppose we have an unsorted log file of accesses to web resources. Each log entry consists of an access time, the ID of the user making the access, and the resource ID.

The access time is represented as seconds since 00:00:00, and all times are assumed to be in the same day.

Example:
logs1 = [
    ["58523", "user_1", "resource_1"],
    ["62314", "user_2", "resource_2"],
    ["54001", "user_1", "resource_3"],
    ["200", "user_6", "resource_5"],
    ["215", "user_6", "resource_4"],
    ["54060", "user_2", "resource_3"],
    ["53760", "user_3", "resource_3"],
    ["58522", "user_22", "resource_1"],
    ["53651", "user_5", "resource_3"],
    ["2", "user_6", "resource_1"],
    ["100", "user_6", "resource_6"],
    ["400", "user_7", "resource_2"],
    ["100", "user_8", "resource_6"],
    ["54359", "user_1", "resource_3"],

]

Example 2:
logs2 = [
    ["300", "user_1", "resource_3"],
    ["599", "user_1", "resource_3"],
    ["900", "user_1", "resource_3"],
    ["1199", "user_1", "resource_3"],
    ["1200", "user_1", "resource_3"],
    ["1201", "user_1", "resource_3"],
    ["1202", "user_1", "resource_3"]
]

Example 3:
logs3 = [
    ["300", "user_10", "resource_5"]
]

Write a function that takes the logs and returns the resource with the highest number of accesses in any 5 minute window, together with how many accesses it saw.

Expected Output:
most_requested_resource(logs1) # => ('resource_3', 3)
Reason: resource_3 is accessed at 53760, 54001, and 54060

most_requested_resource(logs2) # => ('resource_3', 4)
Reason: resource_3 is accessed at 1199, 1200, 1201, and 1202

most_requested_resource(logs3) # => ('resource_5', 1)
Reason: resource_5 is accessed at 300

Complexity analysis variables:

n: number of logs in the input

*/



unordered_map<string, vector<int>> getSortedAccessTimes(vector<vector<string>> logs) {
  unordered_map<string, vector<int>> accesTimes;

  for(int i = 0; i<logs.size(); i++) {
    string user = logs[i][1];
    int num = stoi(logs[i][0]);

    if(accesTimes.find(logs[i][1]) != accesTimes.end()) {
      if(accesTimes[user][0] > num)
        accesTimes[user][0] = num;
      else if(accesTimes[user][1] < num)
        accesTimes[user][1] = num;
    }
    else {
      accesTimes[user] = {num,num};
    }
  }
  return accesTimes;
}

vector<string> getMostAccessedResource(vector<vector<string>> logs) {
  unordered_map<string, vector<int>> accesTimes;
  int max= 0;
  string resourceMax;


  for(int i = 0; i<logs.size(); i++) {
    string resource = logs[i][2];
    int num = stoi(logs[i][0]);

    while(accesTimes[resource].size() > 0 && accesTimes[resource][0] < num - 300) {
      accesTimes[resource].erase(accesTimes[resource].begin());
    }
    accesTimes[resource].push_back(num);

    if(accesTimes[resource].size() > max) {
      max = accesTimes[resource].size();
      resourceMax = resource;
    }
  }

  return {resourceMax, to_string(max)};
}

void printSolution(unordered_map<string, vector<int>> accessTimes) {
  for(auto itr = accessTimes.begin(); itr != accessTimes.end(); itr++) {
    cout << itr->first << " " << itr->second[0] << "," << itr->second[1] << "\n";
  }
}

int main() {
  vector<vector<string>> logs1 = {
      { "58523", "user_1", "resource_1" },
      { "62314", "user_2", "resource_2" },
      { "54001", "user_1", "resource_3" },
      { "200", "user_6", "resource_5" },
      { "215", "user_6", "resource_4" },
      { "54060", "user_2", "resource_3" },
      { "53760", "user_3", "resource_3" },
      { "58522", "user_22", "resource_1" },
      { "53651", "user_5", "resource_3" },
      { "2", "user_6", "resource_1" },
      { "100", "user_6", "resource_6" },
      { "400", "user_7", "resource_2" },
      { "100", "user_8", "resource_6" },
      { "54359", "user_1", "resource_3"},
  };

  vector<vector<string>> logs2 = {
      {"300", "user_1", "resource_3"},
      {"599", "user_1", "resource_3"},
      {"900", "user_1", "resource_3"},
      {"1199", "user_1", "resource_3"},
      {"1200", "user_1", "resource_3"},
      {"1201", "user_1", "resource_3"},
      {"1202", "user_1", "resource_3"},
  };

  vector<vector<string>> logs3 = {
      {"300", "user_10", "resource_5"},
  };

  printSolution(getSortedAccessTimes(logs1));
  vector<string> res = getMostAccessedResource(logs1);
  cout << res[0] << " : " << res[1];

//   printSolution(getSortedAccessTimes(logs2));
//   printSolution(getSortedAccessTimes(logs3));
  return 0;
}

// time - O(n)
// space for solution- O(n)
