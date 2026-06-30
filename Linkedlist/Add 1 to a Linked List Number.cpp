#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev = nullptr;
        while(head){
            Node* next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        if(!head) return nullptr;
        head = reverse(head);
        Node* temp = head;
        int carry = 1;
        while(temp && carry > 0){
            int sum = temp-> data + carry;
            temp -> data = sum % 10;
            carry = sum / 10;
            
            if(!temp-> next && carry > 0){
                temp -> next = new Node(0);
            }
            temp = temp -> next;
        }
        return reverse(head);
    }
};