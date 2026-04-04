#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis, vector<int>& pathvis, vector<int>& topo){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,topo)==false) return false;
            }
            else if(!pathvis[it]) return false;
        }
        pathvis[node] = 0;
        topo.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses);
        vector<int> pathvis(numCourses);
        vector<int> topo;
        for(int i = 0; i < numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,topo)==false) return {};
            }
        }
        reverse(topo.begin(),topo.end());
        return topo;
    }
};