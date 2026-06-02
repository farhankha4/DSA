#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int i,string s,long long num,int sign){
        if(i >= s.length() || !isdigit(s[i])){
            return (int)(num * sign);
        }
        num = num * 10 + (s[i] - '0');

        if(num * sign >= INT_MAX) return INT_MAX;
        if(num * sign <= INT_MIN) return INT_MIN;

        return helper(i + 1, s, num,sign);
    }
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        while(i < s.size() && s[i]==' ') i++;
        if(i < s.size()&&(s[i]=='-'||s[i]=='+')){
            sign = (s[i]=='-'?-1:1);
            i++;
        }
        return helper(i,s,0,sign);
    }
};