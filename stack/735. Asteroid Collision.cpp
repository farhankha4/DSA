#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i]>0) st.push_back(asteroids[i]);
            else{
                while(!st.empty() && abs(asteroids[i])>st.back() && st.back()>0){
                    st.pop_back();
                }
                if(!st.empty() && abs(asteroids[i])==st.back() && st.back()>0){
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                }
            }

        }
        return st;
    }
};