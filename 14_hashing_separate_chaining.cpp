// Q14 AIM: Hash keys 23,45,12,34,56,78,90 into size-7 table with separate chaining.
#include <iostream>
#include <vector>
using namespace std;
int main(){vector<int>t[7];for(int x:{23,45,12,34,56,78,90})t[x%7].push_back(x);for(int i=0;i<7;i++){cout<<i<<": ";for(int x:t[i])cout<<x<<" -> ";cout<<"NULL\n";}}