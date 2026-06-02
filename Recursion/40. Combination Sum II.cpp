#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combinations(int index,vector<vector<int>>& ans, vector<int>& ds, vector<int>& candidates,int target){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            combinations(index + 1,ans,ds,candidates,target - candidates[index]);
            ds.pop_back();
        }
        combinations(index + 1,ans,ds,candidates,target - candidates[index]);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0,ans,ds,candidates,target);
        return ans;
        
    }
};