#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans(n,0);
        int index = right;
        while(left <= right){
            if(abs(nums[left])<abs(nums[right])){
                ans[index] = nums[right] * nums[right];
                right--;
                index--;
            }
            else if(abs(nums[left])>=abs(nums[right])){
                ans[index] = nums[left] * nums[left];
                index--;
                left++;
            }
        }
        return ans;
    }
};