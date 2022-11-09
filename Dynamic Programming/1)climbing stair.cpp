//https://leetcode.com/problems/climbing-stairs/

    #include<bits/stdc++.h>
    using namespace std;
    
    int helpr_space_opt(int n){
        vector<int> dp(n + 1);
        int prev2 = 1;
        int prev = 1;
        for(int i = 2; i<=n; i++){
             int first = prev;
             int second = prev2;
            int curr = first + second;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    int helpr_tebu(int n){
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
             int first = dp[i - 1];
             int second = dp[i - 2];
            dp[i] = first + second;
        }
        
        return dp[n];
    }
    int helper_Memo(int n, vector<int> &dp){
        if(n == 0){
            return 1;
        }

        if(n == 1){
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        int first = helper_Memo(n - 1, dp);
        int second = helper_Memo(n - 2, dp );
        
        return dp[n] = first + second;
    }
    int climbStairs(int n) {
        
        vector<int> dp(n + 1, -1);
        
        return helper_Memo(n, dp);
        
    }


    int main(){
        int n;
        cin >> n;
        cout << climbStairs(n);
    }