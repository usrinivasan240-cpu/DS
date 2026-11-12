// Q16 AIM: Evaluate postfix expression 5 3 + 8 2 - * using a stack.
#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s[]={
        "5","3","+","8","2","-","*"
    };
    stack<int>st;
    for(string t:s){
        if(t=="+"||t=="-"||t=="*"){
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            st.push(t=="+"?a+b:t=="-"?a-b:a*b);
        }
        else st.push(stoi(t));
    }
    cout<<"Result = "<<st.top()<<'\n';
}
