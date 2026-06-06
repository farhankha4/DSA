#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool issub(int index, int target,vector<int>& arr){
        if(target == 0) return true;
        if(index >= arr.size()) return false;
        for(int i = index; i < arr.size();i++){
            if(arr[i]>target) continue;
            if(issub(i+1 ,target - arr[i],arr )) return true;
        }
        return false;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return issub(0,sum,arr);
        
    }
};