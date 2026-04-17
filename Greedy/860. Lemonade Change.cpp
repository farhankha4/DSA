#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0; i < bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10 && five>0){
                ten++;
                five--;
            }
            else if(bills[i]==20 && five>0 && ten>0){
                five--;
                ten--;
                twenty++;
            }
            else if(bills[i]==20 && five>=3 ){
                five -= 3;
                twenty++;
            }
            else{
                return false;
            }

        }
        return true;
    }
};