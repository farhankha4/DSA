#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> path(int n, vector<vector<int>> &edges, int m) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i = 1; i <= n;i++) parent[i] = i;
        dist[1]= 0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                if(dis + weight < dist[adjNode]){
                    dist[adjNode] = dis + weight;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        int node = n;
        vector<int> path;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};