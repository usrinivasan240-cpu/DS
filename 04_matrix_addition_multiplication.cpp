// Q4 AIM: Read two 3x3 matrices; display their sum and product.
#include <iostream>
using namespace std;
int main(){
    int a[3][3],b[3][3],s[3][3],m[3][3]={
    };
    cout<<"Enter matrix A:\n";
    for(auto&r:a)for(int&x:r)cin>>x;
    cout<<"Enter matrix B:\n";
    for(auto&r:b)for(int&x:r)cin>>x;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        s[i][j]=a[i][j]+b[i][j];
        for(int k=0;k<3;k++)m[i][j]+=a[i][k]*b[k][j];
    }
    cout<<"Addition:\n";
    for(auto&r:s){
        for(int x:r)cout<<x<<' ';
        cout<<'\n';
    }
    cout<<"Multiplication:\n";
    for(auto&r:m){
        for(int x:r)cout<<x<<' ';
        cout<<'\n';
    }
}
