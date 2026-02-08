#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int countZero = 0;
        int maxLen = 0;
        while(r < n){
            if(nums[r]==0){
                countZero++;
                while(countZero > k){
                    if(nums[l]==0){
                        countZero--;
                    }
                    l++;
                }
            }
            maxLen = max(maxLen , r - l + 1);
            r++;
        }
        return maxLen;
    }
};