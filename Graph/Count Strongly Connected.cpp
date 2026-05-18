//GFG question
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj,stack<int>& st, vector<int>& vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,st,vis);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<vector<int>>& trans, vector<int>& vis){
        vis[node] = 1;
        for(auto it: trans[node]){
            if(!vis[it]){
                dfs2(it,trans,vis);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        int ssc = 0;
        vector<vector<int>> trans(V);
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                trans[it].push_back(i);
            }
        }
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ssc++;
                dfs2(node,trans,vis);
            }
        }
        return ssc;
    }
};