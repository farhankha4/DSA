#include<bits/stdc++.h>
using namespace std;
class Disjoint {
public:
    vector<int> parent,rank,size;
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpair(int node){
        if(node == parent[node]) 
            return node;
        return parent[node] = findUpair(parent[node]);
    }
    void unionbyrank(int u, int v){
        int ulp_u = findUpair(u);
        int ulp_v = findUpair(v);
        if(ulp_u ==ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionbysize(int u, int v){
        int ulp_u = findUpair(u);
        int ulp_v = findUpair(v);
        if(ulp_u ==ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int countExtras = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUpair(u)== ds.findUpair(v)){
                countExtras++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int component = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) component++;
        }
        int ans = component -1;
        if(ans <= countExtras) return ans;
        return -1;
    }
};