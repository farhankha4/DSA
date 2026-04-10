//gfg question 
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if(grid[source.first][source.second] == 0|| grid[destination.first][destination.second] == 0){
            return -1;
        }
        if(source == destination) return 0;
        vector<vector<int>> dist(n , vector<int>(m,1e9));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >= 0 && nr < n && nc >=0 && nc < m && dis + 1 < dist[nr][nc] && grid[nr][nc]==1){
                    dist[nr][nc] = dis + 1;
                    if(destination.first == nr && destination.second == nc){
                        return dis + 1;
                    }
                    q.push({dis + 1, {nr,nc}});
                }
            }
        }
        return -1;
    }
};
