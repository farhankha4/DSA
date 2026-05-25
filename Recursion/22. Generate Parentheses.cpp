#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void solution(int open, int close,string current,vector<string>& ans,int n){
        if(current.length() == 2*n){
            ans.push_back(current);
            return;
        }
        if(open < n){
            solution(open+1,close,current + '(' , ans , n );
        }
        if(close < open){
            solution(open,close + 1, current + ')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solution(0,0,"",ans,n);
        return ans;
    }
};