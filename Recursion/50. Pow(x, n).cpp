#include<bits/stdc++.h>
using namespace std;
class Solution {
    int power(double x, int n){
        if(n == 0) return 1.0;
        double half = power(x ,n/2);

        if(n%2==0){
            return half * half;
        }
        return(x * half * half);
    }
public:
    double myPow(double x, int n) {
        double num = n;
        if(num < 0){
            return (1 / power(x , num * -1));
        }
        return power(x,num);
    }
};