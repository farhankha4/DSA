#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(st.begin());
            for(auto i:adj[node]){
                int adjNode = i.first;
                int weight = i.second;
                if(dist[node] + weight < dist[adjNode]){
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode],adjNode});
                    dist[adjNode] = dist[node] + weight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};