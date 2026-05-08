//gfg prism minimum weight spanning tree
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt}); 
            adj[v].push_back({u,wt}); 
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum = 0;
        vector<int> vis(V, 0);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if(vis[node]==1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                if(!vis[adjnode]){
                    pq.push({edw,adjnode});
                }
            }
        }
        return sum;
    }
};