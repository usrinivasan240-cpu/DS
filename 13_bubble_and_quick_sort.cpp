// Q13 AIM: Sort input integers using bubble sort and quick sort.
#include <iostream>
#include <vector>
using namespace std;
void bubble(vector<int>&a){for(int i=0;i<(int)a.size()-1;i++){bool ch=false;for(int j=0;j<(int)a.size()-i-1;j++)if(a[j]>a[j+1])swap(a[j],a[j+1]),ch=true;if(!ch)break;}}int part(vector<int>&a,int l,int r){int p=a[r],i=l;for(int j=l;j<r;j++)if(a[j]<=p)swap(a[i++],a[j]);swap(a[i],a[r]);return i;}void quick(vector<int>&a,int l,int r){if(l<r){int p=part(a,l,r);quick(a,l,p-1);quick(a,p+1,r);}}
int main(){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;auto b=a; bubble(a);quick(b,0,n-1);for(int x:a)cout<<x<<' ';cout<<"\n";for(int x:b)cout<<x<<' ';cout<<'\n';}