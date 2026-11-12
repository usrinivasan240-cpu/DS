// Q7 AIM: Insert 10,20,30,40,50,25 into AVL tree and rebalance with rotations.
#include <iostream>
#include <algorithm>
using namespace std;
struct N{int x,h;N*l,*r;N(int v):x(v),h(1),l(nullptr),r(nullptr){}};int H(N*n){return n?n->h:0;}int B(N*n){return n?H(n->l)-H(n->r):0;}void U(N*n){n->h=1+max(H(n->l),H(n->r));}
N*R(N*y){N*x=y->l,*t=x->r;x->r=y;y->l=t;U(y);U(x);return x;}N*L(N*x){N*y=x->r,*t=y->l;y->l=x;x->r=t;U(x);U(y);return y;}
N*ins(N*n,int x){if(!n)return new N(x);if(x<n->x)n->l=ins(n->l,x);else if(x>n->x)n->r=ins(n->r,x);else return n;U(n);int b=B(n);if(b>1&&x<n->l->x)return R(n);if(b<-1&&x>n->r->x)return L(n);if(b>1){n->l=L(n->l);return R(n);}if(b<-1){n->r=R(n->r);return L(n);}return n;}
void pre(N*n){if(n){cout<<n->x<<"(BF="<<B(n)<<") ";pre(n->l);pre(n->r);}}
int main(){N*r=nullptr;for(int x:{10,20,30,40,50,25}){r=ins(r,x);cout<<"After "<<x<<": ";pre(r);cout<<'\n';}}