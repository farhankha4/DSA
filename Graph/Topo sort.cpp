#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        vector<int> vis(V,0);
        vector<vector<int>> adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            int num = st.top();
            st.pop();
            ans.push_back(num);
        }
        return ans;
    }
};