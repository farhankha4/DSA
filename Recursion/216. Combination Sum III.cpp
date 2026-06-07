#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    void combination(int ind, vector<int>& ds, vector<vector<int>>& ans,int k ,int n){
        if(k == 0 && n == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i <= 9; i++){
            if(i > n) break;
            ds.push_back(i);
            combination(i + 1,ds , ans, k-1 , n - i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        combination(1,ds,ans, k ,n);
        return ans;
    }
};