// Q1 AIM: Stack ADT using array: PUSH, POP, PEEK, DISPLAY; overflow/underflow.
#include <iostream>
#include <string>
using namespace std;
const int CAP=5;
class Stack{string a[CAP];int top=-1;public:void push(string x){if(top==CAP-1)cout<<"Stack overflow\n";else a[++top]=x;}void pop(){if(top<0)cout<<"Stack underflow\n";else cout<<"Removed: "<<a[top--]<<'\n';}void peek(){if(top<0)cout<<"Empty\n";else cout<<"Current: "<<a[top]<<'\n';}void display(){for(int i=top;i>=0;i--)cout<<a[i]<<'\n';if(top<0)cout<<"Empty\n";}};
int main(){Stack s;int c;string x;do{cout<<"1.Push 2.Pop 3.Peek 4.Display 0.Exit: ";cin>>c;if(c==1){cin>>x;s.push(x);}else if(c==2)s.pop();else if(c==3)s.peek();else if(c==4)s.display();}while(c);}