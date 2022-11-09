// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int profit = INT_MIN;
        for(auto it: prices){
            low = min(low, it);
            profit = max(it - low, profit);
        }
        return profit;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr (n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout <<  maxProfit(arr);
    
}