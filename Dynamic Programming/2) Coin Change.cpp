//https://leetcode.com/problems/coin-change-ii/

#include<bits/stdc++.h>
using namespace std;

int helper_tebu( vector<int>& arr, int T, int n){
       vector<vector<int>> dp(n,vector<int>(T+1,0));
        for(int i=0;i<=T;i++){
            if(i%arr[0]==0){
                dp[0][i]=1;
            }
       
        }
        for(int ind=1; ind<n;ind++){
            for(int target=0;target<=T;target++){
                int notTaken = dp[ind-1][target];
            
                int taken = 0;
                if(arr[ind]<=target){
                    taken = dp[ind][target-arr[ind]];
                }
                
                dp[ind][target] = notTaken + taken;
            }
        }
        
        return dp[n - 1] [T];
        
}
int helper_memo(int idx, vector<int>& arr, int target, vector<vector<int>> &dp){
    if(idx == 0){
        return (target % arr[0] == 0);
    }
    if(dp[idx][target] != -1) return dp[idx][target];
        int pick = 0;
    if(arr[idx] <= target){   // pick condition 
        pick = helper_memo(idx, arr, target - arr[idx], dp);
          
    }
        
    // not pick condition
    int notPick = helper_memo(idx - 1,arr,  target, dp);
         
    return dp[idx][target] =  pick + notPick;
}
int change(int sum, vector<int>& coin) {
    vector<vector<int>> dp(coin.size() , vector<int> (sum + 1, -1));
    return helper_memo(coin.size() - 1 , coin, sum, dp);
      
}

int main(){
    int n;
    cin >> n;
    int traget ;
    cin >> traget;
    vector<int> coin(n);
    for(int i = 0; i<n ; i++){
        cin >> coin[i];
    }
    change(traget, coin);
}
