#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone:stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            if(num1==num2) continue;
            else{
                pq.push(num1 - num2);
            }
        }
        if(pq.size()==1) return pq.top();
        return pq.empty() ? 0 : pq.top();
    }
};