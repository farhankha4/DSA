#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* next;
    node(int data1){
        data = data1;
        next = nullptr;
    }
};
node* arraytoll(vector<int> nums){
    node* head = new node(nums[0]);
    node* mover = head;
    for(int i = 1; i<nums.size();i++){
        node * temp = new node(nums[i]);
        mover->next = temp;
        mover = mover->next;        
    }
    return head;
}

int main(){
    int top = -1;
    int stack[10];
    cout<<"1.push"<<endl;
    cout<<"2.pop"<<endl;
    cout<<"3.peak"<<endl;
    cout<<"4.exit"<<endl;
    int i = 0;
    while(i)
    



}