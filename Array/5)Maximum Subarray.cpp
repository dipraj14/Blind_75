// https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;


int maxSub(vector<int> arr){
    int curr = 0 ;
    int maxi = INT_MIN;

    for(auto it: arr){
        curr += it;
        maxi = max(curr, maxi);

        if(curr < 0){
            curr = 0;
        }
    }

    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0 ; i<n; i++){
        cin >> arr[i];
    }
    cout << maxSub(arr);
}