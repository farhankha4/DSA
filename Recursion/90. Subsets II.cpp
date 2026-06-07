#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination(int ind,vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            combination(i + 1, ds, ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        combination(0,ds,ans,nums);
        return ans;
    }
};