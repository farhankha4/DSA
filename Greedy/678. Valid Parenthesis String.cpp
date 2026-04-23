#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0; int maxi = 0;
        for(char c:s){
            if(c=='('){
                mini++;
                maxi++;
            }
            else if(c==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            mini = max(mini,0);
            if(maxi < 0) return false;
        }
        return mini == 0;
    }
};