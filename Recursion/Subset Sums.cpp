#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void sums(int index, int sum, int N,vector<int>& ans,vector<int>& arr){
        if(index == N){
            ans.push_back(sum);
            return;
        }

        sums(index + 1, sum + arr[index],N,ans,arr);
        sums(index + 1, sum ,N,ans,arr);
    }
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        sums(0,0,n,ans,arr);
        sort(ans.begin(),ans.end());
        return ans;
    }
};