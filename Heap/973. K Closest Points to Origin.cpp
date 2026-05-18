#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        for(int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            pq.push({dis,i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};