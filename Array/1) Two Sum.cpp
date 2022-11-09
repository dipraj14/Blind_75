// https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int t){
    unordered_map<int,int> mp;
    int n = arr.size();
    for(int i=0; i<n; i++){
        mp[arr[i]] = i;
    }

    for(int i = 0; i<n; i++){
        int remSum = (t - arr[i]);
        if(mp.find(remSum) != mp.end() && mp[remSum] != i){
            return {mp[remSum], i};
        }
    }
    return {};
}

int main(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> arr (n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> ans = twoSum(arr, t);
    for(auto it: ans) cout << it <<" ";
}