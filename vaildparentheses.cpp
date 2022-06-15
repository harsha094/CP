#include<iostream>
#include<stack>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>s;
    for(int i=0;i<expression.length();i++){
        char ch = expression[i];
        
        // if opening brackets - stackpush
        // if closing brckets - stacktop check and pop
        
        if(ch =='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            // for closing brackets
            //check stack is empty or not
            if(!s.empty()){
                char top = s.top();
                if((ch ==')' && top =='(') || (ch =='}' && top =='{')|| (ch ==']' && top =='[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
           }
    }
      if(s.empty())
          return true;
      else
          return false;
       
}
//Time complexity: O(n)