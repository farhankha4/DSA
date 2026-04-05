#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev;
        vector<int> inDegree(n,0);
        for(int i = 0; i < n; i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNode;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNode.push_back(node);
            for(auto it:adjRev[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
    }
};