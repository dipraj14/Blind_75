// https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

    bool helper(string s, vector<string>& wordDict, int pos, unordered_map<int, bool> &mp, set<string> &st){
        if(pos == s.size()) return true;
        if(mp.count(pos)) return mp[pos];
        
        string t = "";
        for(int i = pos; i< s.size(); i++){
            auto it = st.find(s.substr(pos, i - pos + 1));
            if(it != st.end() && helper(s, wordDict, i + 1, mp, st)) {
                return mp[pos] = true;  
            }
        }
        return mp[pos] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it: wordDict){
            st.insert(it);
        }
        unordered_map<int, bool> mp;
       return helper(s, wordDict, 0, mp, st);
    }

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> wordDict(n);
    for(int i =0 ; i<n; i++){
        cin >> wordDict[i];
    }
    cout << wordBreak(s, wordDict);
}