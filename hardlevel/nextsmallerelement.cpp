#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        //stack ka top is answer
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}