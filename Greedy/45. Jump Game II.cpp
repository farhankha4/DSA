#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int index, vector<int>& nums) {
        if (index >= nums.size() - 1) return 0;

        int steps = nums[index];
        int minJumps = INT_MAX;
        for (int i = 1; i <= steps; i++) {
            int next = index + i;
            if (next < nums.size()) {
                int jumps = solve(next, nums);
                if (jumps != INT_MAX) {
                    minJumps = min(minJumps, 1 + jumps);
                }
            }
        }

        return minJumps;
    }

    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};