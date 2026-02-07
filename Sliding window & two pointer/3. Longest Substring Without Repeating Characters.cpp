#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hashLen = 256;
        int hash[hashLen];
        for(int i = 0; i < hashLen; ++i){
            hash[i] = -1;
        }
        int r = 0; 
        int l = 0; 
        int maxLen = 0;
        while(r<n){
            if(hash[s[r]]!=-1){
                l = max(hash[s[r]] +1 , l);
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};