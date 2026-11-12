// Q9 AIM: Dijkstra shortest paths from A. Enter adjacency matrix; 0 means no edge.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>g(n,vector<int>(n));for(auto&r:g)for(int&x:r)cin>>x;vector<int>d(n,INT_MAX),p(n,-1);vector<bool>u(n);d[0]=0;for(int z=0;z<n;z++){int v=-1;for(int i=0;i<n;i++)if(!u[i]&&(v<0||d[i]<d[v]))v=i;if(v<0||d[v]==INT_MAX)break;u[v]=1;for(int w=0;w<n;w++)if(g[v][w]>0&&d[v]<=INT_MAX-g[v][w]&&d[v]+g[v][w]<d[w])d[w]=d[v]+g[v][w],p[w]=v;}for(int v=0;v<n;v++){cout<<char('A'+v)<<": ";if(d[v]==INT_MAX){cout<<"unreachable\n";continue;}vector<int>a;for(int x=v;x!=-1;x=p[x])a.push_back(x);reverse(a.begin(),a.end());for(int x:a)cout<<char('A'+x)<<' ';cout<<"distance="<<d[v]<<'\n';}}