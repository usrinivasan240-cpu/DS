// Q15 AIM: Circular linked list insert, delete value, display wrap-around.
#include <iostream>
using namespace std;
struct N{int x;N*n;N(int v):x(v),n(nullptr){}};class C{N*t=nullptr;public:~C(){if(!t)return;N*p=t->n;t->n=nullptr;while(p){N*q=p;p=p->n;delete q;}}void add(int x){N*q=new N(x);if(!t)q->n=q,t=q;else q->n=t->n,t->n=q,t=q;}void del(int x){if(!t){cout<<"Empty\n";return;}N*p=t,*q=t->n;do{if(q->x==x){if(q==p)t=nullptr;else{p->n=q->n;if(q==t)t=p;}delete q;return;}p=q;q=q->n;}while(q!=t->n);cout<<"Not found\n";}void show(){if(!t){cout<<"Empty\n";return;}N*p=t->n;do{cout<<p->x<<" -> ";p=p->n;}while(p!=t->n);cout<<"back to first\n";}};
int main(){C c;int op,x;do{cin>>op;if(op==1)cin>>x,c.add(x);else if(op==2)cin>>x,c.del(x);else if(op==3)c.show();}while(op);}