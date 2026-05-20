#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch - 'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push({freq[i],char('a'+i)});
            }
        }
        string ans = "";
        pair<int,char> prev = {0,'#'};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int frequency = it.first;
            int ch = it.second;
            frequency--;
            ans += ch;
            if(prev.first > 0){
                pq.push(prev);
            }
            prev = {frequency,ch};
        }
        if(s.length() != ans.length())  return "";
        return ans;
    }
};