/******************************************************************************

I  have a number of jobs running on my server, say, A, B, C, D. Some jobs have dependency on some other jobs, say A ⇒ B,C  B ⇒ X,Y .i
Gven a HashMap with jobs versus their list of dependencies, write a program to predict if there is a possibility of deadlock/circular
dependency.

Sample input

[A] - [ B ,X,Y]
[B] - [X,K]
[K] - [M]

RESULT NO DEADLOCK

[A] - [ B ,X,Y]
[B] - [X,K]
[K] - [M]
[M] - [A]

RESULT DEADLOCK

*******************************************************************************/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string checkDep(unordered_map<char, vector<char>> map) {
    bool res= true;
    stack<char> stack;

    for(auto m: map) {
        for (char dep: m.second) {
            stack.push(dep);
        }
        while(stack.size() > 0) {
            if(stack.top() == m.first) {
                res=false;
                return "Deadlocked";
            }

            char stack_top = stack.top();
            stack.pop();

            if (map.find(stack_top) != map.end()) {
                for (char dep: map.find(stack_top) -> second) {
                    stack.push(dep);
                }
            }
        }
    }
    return "Not deadlocked";
}



int main(){
    unordered_map<char, vector<char>> umap;

    umap['A'] = {'B','X','Y'};
    umap['B'] = {'X','K'};
    umap['K'] = {'M'};
    umap['M'] = {'A'};
    cout << "input1 " << checkDep(umap) << endl;

    umap.clear();


    umap['A'] = {'B','X','Y'};
    umap['B'] = {'X','K'};
    umap['K'] = {'M'};


    cout << "input2 " << checkDep(umap) << endl;

    return 0;
}

