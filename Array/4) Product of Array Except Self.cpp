// https://leetcode.com/problems/product-of-array-except-self/

#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        
        vector<int> prefix(n),sufix(n);
        
         prefix[0] = nums[0];
        sufix[n-1] = nums[n - 1];
        
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i - 1] * nums[i];
        }
        for(int  i = nums.size() - 2; i >= 0 ; i--){
            sufix[i] = sufix[i + 1] * nums[i];
        }
        
        vector<int> ans(n);
        ans[0] = sufix[1];
        ans[n - 1] = prefix[n - 2];
        
        for(int i = 1; i <= n - 2; i++){
            ans[i] = (prefix[i - 1] * sufix[i + 1]);
        }
        
        return ans;
    }

int main(){
     int n;
    cin >> n;
    vector<int> arr (n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> ans =  productExceptSelf(arr);

    for(auto it: ans){
        cout << it <<" ";
    }
}