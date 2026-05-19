#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> sortedTask;
        int n = tasks.size();
        for(int i = 0; i < n; i++){
            sortedTask.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTask.begin(),sortedTask.end());
        long long time = 0; 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int i = 0;
        vector<int> ans;
        while(i < n || !pq.empty()){
            if(pq.empty()){
                time = max(time,(long long) sortedTask[i][0]);
            }
            while(i < n && sortedTask[i][0] <= time){
                pq.push({sortedTask[i][1],sortedTask[i][2]});
                i++;
            }
            auto it = pq.top();
            pq.pop();
            time += it.first;
            ans.push_back(it.second);
        }
        return ans;
    }
};