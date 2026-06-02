#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination(vector<vector<int>>& ans,int target,int index,vector<int>& ds,vector<int>& candidates){
        if(index == candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            combination(ans,target - candidates[index],index,ds,candidates);
            ds.pop_back();
        }
        combination(ans,target,index + 1, ds, candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combination(ans,target,0,ds,candidates);
        return ans;
    }
};