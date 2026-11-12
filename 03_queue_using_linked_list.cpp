// Q3 AIM: Queue using linked list; enqueue customers, dequeue served customer, display.
#include <iostream>
#include <string>
using namespace std;
struct N{string s;N*n;N(string x):s(x),n(nullptr){}};
class Queue{N*f=nullptr,*r=nullptr;public:~Queue(){while(f){N*t=f;f=f->n;delete t;}}void enqueue(string s){N*x=new N(s);if(r)r->n=x;else f=x;r=x;}void dequeue(){if(!f){cout<<"Queue empty\n";return;}N*t=f;cout<<"Served: "<<t->s<<'\n';f=f->n;if(!f)r=nullptr;delete t;}void display(){if(!f)cout<<"Queue empty\n";for(N*p=f;p;p=p->n)cout<<p->s<<" <- ";cout<<"END\n";}};
int main(){Queue q;int c;string s;do{cout<<"1.Enqueue 2.Dequeue 3.Display 0.Exit: ";cin>>c;if(c==1){cin>>ws;getline(cin,s);q.enqueue(s);}else if(c==2)q.dequeue();else if(c==3)q.display();}while(c);}