#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr= 1; int ans = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1]){
                if(i >=2 && arr[i-1] > arr[i-2]) curr++;
                else curr = 2;
            }
            else if(arr[i] > arr[i-1]){
                if(i >=2 && arr[i-1] < arr[i-2]) curr++;
                else curr = 2;
            }
            else{
                curr = 1;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};