#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis,int dx[],int dy[]){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    dfs(nrow,ncol,grid,vis,dx,dy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(i,j,grid,vis,dx,dy);
                }
            }
        }
        return count;
    }
};