#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count (26,0);
        for(char c : s){
            count[c - 'a']++;
        }
        string ans = "";
        for(char c : order){
            int ind = c - 'a';
            while(count[ind] > 0){
                ans += 'a' + ind;
                count[ind]--;
            }
        }
        for(int i = 0; i < 26; i++){
            int c = 'a' + i;
            while(count[i] > 0){
                ans += c;
                count[i]--;
            }
        }
        return ans;

    }
};