// https://leetcode.com/problems/contains-duplicate/

#include<bits/stdc++.h>
using namespace std;

bool containDup(vector<int> &arr){
    return arr.size() != set<int> (arr.begin(), arr.end()).size();
}

int main(){
    int n;
    cin >> n;
    vector<int> arr (n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout <<  containDup(arr);
    
}