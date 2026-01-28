#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> solution(n);
        stack<int> st;
        for(int i = 2*n -1; i >=0; i--){
            int index  = i%n;
            int currElement = nums[index];
            while(!st.empty() && st.top()<=currElement) st.pop();
            if(i<n){
                if(st.empty()) solution[i] = -1;
                else solution[i]=st.top();
            }
            st.push(nums[index]);
        }
        return solution;
    }
};