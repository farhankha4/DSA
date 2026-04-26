#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = 0; int nmaxi = INT_MIN;
        int mini = 0; int nmini = INT_MAX;
        int total = 0;
        for(int x : nums){
            maxi = max(x , maxi+x);
            nmaxi = max(nmaxi , maxi);

            mini = min(x , mini+x);
            nmini = min(nmini , mini);

            total += x;
        }
        if(nmaxi < 0) return nmaxi;
        return max(nmaxi , total - nmini);
    }
};