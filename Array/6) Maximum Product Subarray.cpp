
// https://leetcode.com/problems/maximum-product-subarray/

#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {

    int maxL = INT_MIN;
    int product = 1;
    int maxR = INT_MIN;

    for(auto it: nums){
        product *= it;
        maxL = max(product, maxL);
        if(product == 0) {
            product = 1;
        }
    }
    product = 1;
    for(auto it = nums.rbegin(); it != nums.rend(); it++){
        product *= (*it);
        maxR = max(product, maxR);
        if(product == 0) {
            product = 1;
        }
    }

    return max(maxL, maxR);

}
int main(){
     int n;
    cin >> n;
    vector<int> arr (n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout <<  maxProduct(arr);

}