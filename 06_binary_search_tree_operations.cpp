// Q6 AIM: BST insert, delete, search and inorder/preorder/postorder traversals.
#include <iostream>
using namespace std;
struct N{int x;N*l,*r;N(int v):x(v),l(nullptr),r(nullptr){}};
N*ins(N*t,int x){if(!t)return new N(x);if(x<t->x)t->l=ins(t->l,x);else if(x>t->x)t->r=ins(t->r,x);return t;}N*mn(N*t){while(t&&t->l)t=t->l;return t;}
N*del(N*t,int x){if(!t)return t;if(x<t->x)t->l=del(t->l,x);else if(x>t->x)t->r=del(t->r,x);else{if(!t->l){N*q=t->r;delete t;return q;}if(!t->r){N*q=t->l;delete t;return q;}N*q=mn(t->r);t->x=q->x;t->r=del(t->r,q->x);}return t;}
bool find(N*t,int x){while(t){if(t->x==x)return true;t=x<t->x?t->l:t->r;}return false;}void in(N*t){if(t){in(t->l);cout<<t->x<<' ';in(t->r);}}void pre(N*t){if(t){cout<<t->x<<' ';pre(t->l);pre(t->r);}}void post(N*t){if(t){post(t->l);post(t->r);cout<<t->x<<' ';}}
int main(){N*r=nullptr;int c,x;do{cout<<"1.Insert 2.Delete 3.Search 4.Traversals 0.Exit: ";cin>>c;if(c>=1&&c<=3){cin>>x;if(c==1)r=ins(r,x);else if(c==2)r=del(r,x);else cout<<(find(r,x)?"Found":"Not found")<<'\n';}else if(c==4){cout<<"Inorder: ";in(r);cout<<"\nPreorder: ";pre(r);cout<<"\nPostorder: ";post(r);cout<<'\n';}}while(c);}