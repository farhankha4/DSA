#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination(int index, string current, string digits, vector<string>& com,vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        string letters = com[digits[index] - '0'];
        for(int i = 0; i < letters.size();i++){
            combination(index + 1,current + letters[i], digits , com,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> com = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        combination(0,"",digits,com,ans);
        return ans;
    }
};