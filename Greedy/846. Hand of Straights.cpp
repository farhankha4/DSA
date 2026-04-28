#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        if(hand.size() % groupSize != 0) return false;
        for(int x : hand){
            mp[x]++;
        }
        for(auto it:mp){
            int start = it.first;
            int count = it.second;
            if(count > 0){
                for(int i = 0; i < groupSize; i++){
                    int curr = i + start;
                    if(mp[curr] < count) return false;
                    mp[curr]--;
                }
            }
        }
        return true;
    }
};