#include<bits/stdc++.h>
using namespace std;
class Solution {
    int power(double x, int n){
        if(n == 0) return 1;
        else if(n==1) return x;
        if(n%2==0){
            
        }
    }
public:
    double myPow(double x, int n) {
        int num = n;
        if(num < 0){
            return (1 / power(x , num * -1));
        }
        return power(x,num);
    }
};