#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findNse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findPse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod  = 1e9 + 7;
        int sum = 0;
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = (right * left * 1LL);
            int val = (freq * arr[i] * 1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};