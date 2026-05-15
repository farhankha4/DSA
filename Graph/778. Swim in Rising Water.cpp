#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isvalid(int row, int col,int n){
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n , vector<int>(n,0));
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > q;
        q.push({grid[0][0],0,0});
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        int ans = 0;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int height = it[0];
            int row = it[1];
            int col = it[2];
            if(visited[row][col]) continue;
            visited[row][col] = 1;
            ans = max(ans,height);

            if(row == n-1 && col == n -1) return ans;
            for(int i = 0 ; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(isvalid(nr,nc,n) && !visited[nr][nc]){
                    q.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return -1;
    }
};