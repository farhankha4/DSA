#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sub(int index, int N, vector<int>& nums, vector<vector<int>>& ans,vector<int>& ds){
        if(index == N){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        sub(index + 1, N, nums, ans, ds);
        ds.pop_back();
        sub(index + 1, N, nums,ans, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        sub(0,n,nums,ans,ds);
        return ans;
    }
};