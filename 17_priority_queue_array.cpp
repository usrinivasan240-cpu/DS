// Q17 AIM: Array priority queue; larger priority number is served first.
#include <iostream>
#include <string>
using namespace std;
struct P{string name;int priority;};class PQ{P a[100];int n=0;public:void add(string s,int p){if(n==100){cout<<"Full\n";return;}int i=n++;while(i&&a[i-1].priority<p)a[i]=a[i-1],i--;a[i]={s,p};}void remove(){if(!n){cout<<"Empty\n";return;}cout<<"Served "<<a[0].name<<'\n';for(int i=1;i<n;i++)a[i-1]=a[i];n--;}void show(){for(int i=0;i<n;i++)cout<<a[i].name<<'('<<a[i].priority<<") ";cout<<'\n';}};
int main(){PQ q;int c,p;string s;do{cin>>c;if(c==1)cin>>s>>p,q.add(s,p);else if(c==2)q.remove();else if(c==3)q.show();}while(c);}