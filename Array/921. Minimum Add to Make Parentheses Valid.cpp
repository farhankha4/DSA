#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int track = 0;
        int rev = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                track++;
            }
            else{
                track--;
                if(track < 0){
                    rev++;
                    track = 0;
                }
            }
        }
        return abs(track) + rev;
    }
};