// Not the optimal solution tho
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }
        vector<int> ans;
        for(auto it:hash){
            if(it.second > n / 3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};