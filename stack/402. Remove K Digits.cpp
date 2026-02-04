#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> st;
        if(k==num.length()){
            return "0";
        }
        int n = num.length();
        for(int i = 0; i < n; i++){
            int digit = num[i]-'0';
            while(!st.empty() && digit < st.back()){
                st.pop_back();
                k--;
            }
            if(n-i == k){
                continue;
                k--;
            }
            else if(st.empty() || st.back()< digit){
                st.push_back(digit);
            }
        }
        string ans = "";
        for(auto it: st){
            ans += 'it';
        }
        return ans;
    }
};