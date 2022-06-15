#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    
    int num= s.top();
    s.pop();
    
    insertAtBottom(s,x);
    s.push(num);
}
void reverseStack(stack<int> &stack) {
    // Write your code
    //base call
    if(stack.empty()){
        return;
    }
    
    int num = stack.top();
    stack.pop();
    //recursive call
    reverseStack(stack);
    insertAtBottom(stack,num);
}
// Time Complexity O(n^2)