// https://leetcode.com/problems/find-all-duplicates-in-an-array/


#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0 ; i < nums.size(); i++){
        if(nums[abs(nums[i]) - 1] < 0){
            ans.push_back(abs(nums[i]));
        }
        nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
    vector<int> ans = findDuplicates(nums);
    for(auto it: ans) cout << it <<" ";
}

// Input: nums = [4,3,2,7,8,2,3,1]
               // 1 2 3 4 5 6 7 8 
// Output: [2,3]