#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timer = 1;
    void dfs(int node , int parent,vector<int> adj[], int tin[],int low[],vector<int>& visited, vector<vector<int>>& bridges){
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it:adj[node]){
            if(it == parent) continue;
            if(visited[it] == 0){
                dfs(it,node, adj, tin,low, visited, bridges);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        vector<int> visited(n , 0);
        dfs(0 , -1, adj, tin, low, visited, bridges);
        return bridges;
    }
};