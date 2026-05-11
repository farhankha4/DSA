#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isvalid(int nr,int nc,int n){
        return nr >= 0 && nc >= 0 && nr < n && nc < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        DisjointSet ds(n * n);
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                for(int i = 0; i < 4; i++){
                    int nr = row + dx[i];
                    int nc = col + dy[i];
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int node = row * n + col;
                        int adjNode = nr * n + nc;
                        ds.unionBySize(node , adjNode);
                    }
                }
            }
        }
        int maxi = 0; 
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                set<int> components;
                for(int i = 0; i < 4; i++){
                    int nr = row + dx[i];
                    int nc = col + dy[i];
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int adjNode = nr * n + nc;
                        components.insert(ds.findUPar(adjNode));
                    }
                }
                int sizeTotal = 1;
                for(auto parent:components){
                    sizeTotal += ds.size[parent];
                }
                maxi = max(maxi,sizeTotal);
            }
        }
        for(int i = 0; i < n*n; i++){
            maxi = max(maxi,ds.size[ds.findUPar(i)]);
        }
        return maxi;
    }
};