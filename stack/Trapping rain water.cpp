#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int rightMax,leftMax,total = 0;
        int left = 0, right = height.size()-1;
        while(right>left){
            if(leftMax<=rightMax){
                if(leftMax>height[left]){
                    total += leftMax - height[left];
                }
                else{
                    leftMax = height[left];
                }
                leftMax++;
            }
            else{
                if(rightMax>height[right]){
                    total += rightMax - height[right];
                }
                else{
                    rightMax = height[right];
                }
                right--;
            }
            return total;
        }
    }
};