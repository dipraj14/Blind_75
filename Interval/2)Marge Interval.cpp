// https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;
// vector<vector<int>> merge(vector<vector<int>>& intervals) { // o(n) // o(1) extra space
        
//         sort(intervals.begin(), intervals.end());
        
//         vector<vector<int>> marge;
        
//         vector<int> temp = intervals[0];
        
//         for(auto it: intervals){  // 1 3 // 2 4
//             if(it[0] <= temp[1]){
//                 temp[1] = max(temp[1], it[1]);
//             }else{
//                 marge.push_back(temp);
//                 temp = it;
//             }
//         }
        
//         marge.push_back(temp);
        
        
//         return marge;
// }
 vector<vector<int>> merge(vector<vector<int>>& intervals) { // // o(n) // o(n) extra space
    sort(intervals.begin(), intervals.end()); 
        stack<vector<int>> st;  // if we use temp vector that was also fine
        st.push(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= st.top()[1]){
                st.top()[0] = min(st.top()[0], intervals[i][0]);
                st.top()[1] = max(st.top()[1], intervals[i][1]);        
            
            }
            else{
                st.push(intervals[i]);
            }
            
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            vector<int> temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
        
    return ans;
 }
int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int> (2));
    for(int  i = 0; i<n; i++){
        for(int j = 0; j < 2; j++){
            cin >> intervals[i][j];
        }
    }
    vector<vector<int>> ans =  merge(intervals);

    for(auto it: ans){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]