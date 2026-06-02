#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void combination(string curr,int n, int &ans){
        if(curr.length()==n){
            ans++;
        }
        combination(curr + '0',n,ans);
        if(curr.empty() || curr.back() != '1'){
            combination(curr + '1',n,ans);
        }
    }
    int countStrings(int n) {
        int ans = 0;
        combination("",n,ans);
        return ans;
    }
};