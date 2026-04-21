#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInt;
        if(intervals.size()==0){
            return mergedInt;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(auto it : intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1],temp[1]);
            }
            else{
                mergedInt.push_back(temp);
                temp = it;
            }
        }
        mergedInt.push_back(temp);
        return mergedInt;
    }
};