// Q12 AIM: Iterative and recursive binary search on a sorted input array.
#include <iostream>
using namespace std;
int it(int*a,int n,int k){
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==k)return m;
        if(a[m]<k)l=m+1;
        else r=m-1;
    }
    return -1;
}
int rec(int*a,int l,int r,int k){
    if(l>r)return -1;
    int m=l+(r-l)/2;
    if(a[m]==k)return m;
    return a[m]<k?rec(a,m+1,r,k):rec(a,l,m-1,k);
}
int main(){
    int n,k;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    int x=it(a,n,k),y=rec(a,0,n-1,k);
    cout<<"Iterative index: "<<x<<"\nRecursive index: "<<y<<'\n';
    delete[]a;
}
