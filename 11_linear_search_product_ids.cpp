// Q11 AIM: Linear search 61 and 50 in {24,17,39,5,61,12,48,30}; positions are 1-based.
#include <iostream>
using namespace std;
int main(){int a[]={24,17,39,5,61,12,48,30};for(int k:{61,50}){int p=-1;for(int i=0;i<8;i++)if(a[i]==k){p=i;break;}if(p<0)cout<<k<<" not found\n";else cout<<k<<" found at position "<<p+1<<'\n';}}