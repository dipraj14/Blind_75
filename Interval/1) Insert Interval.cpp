// https://leetcode.com/problems/insert-interval/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int  i  = 0 ;
    int  n = intervals.size();
    while(i < n && intervals[i][1] <  newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }
    while(i < n && newInterval[1] >= intervals[i][0]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
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
    vector<int> newInterval(2);
    for(int i = 0; i < 2; i++){
            cin >> newInterval[i];
    }
    vector<vector<int>> ans =  insert(intervals, newInterval);

    for(auto it: ans){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]