// Q5 AIM: Convert infix to postfix using stack; ^ is right-associative.
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int pr(char c){
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return 0;
}
string convert(string s){
    stack<char>st;
    string out;
    for(char c:s){
        if(isspace((unsigned char)c))continue;
        if(isalnum((unsigned char)c))out+=c;
        else if(c=='(')st.push(c);
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){
                out+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty()&&st.top()!='('&&(pr(st.top())>pr(c)||(pr(st.top())==pr(c)&&c!='^'))){
                out+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        out+=st.top();
        st.pop();
    }
    return out;
}
int main(){
    string s;
    getline(cin,s);
    cout<<convert(s)<<'\n';
}
