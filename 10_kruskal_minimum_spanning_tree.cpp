// Q10 AIM: Kruskal MST for given weighted edges; expected minimum cost is 8.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct E{
    int u,v,w;
    bool operator<(const E&o)const{
        return w<o.w;
    }
};
struct D{
    vector<int>p,r;
    D(int n):p(n),r(n){
        for(int i=0;i<n;i++)p[i]=i;
    }
    int f(int x){
        return p[x]==x?x:p[x]=f(p[x]);
    }
    bool join(int a,int b){
        a=f(a);
        b=f(b);
        if(a==b)return false;
        if(r[a]<r[b])swap(a,b);
        p[b]=a;
        if(r[a]==r[b])r[a]++;
        return true;
    }
};
int main(){
    vector<E>e={
        {
            1,2,4
        },{
            1,3,3
        },{
            2,3,1
        },{
            2,4,2
        },{
            3,4,4
        },{
            4,5,2
        },{
            3,5,5
        }
    };
    sort(e.begin(),e.end());
    D d(6);
    int sum=0;
    for(auto x:e)if(d.join(x.u,x.v))cout<<x.u<<"-"<<x.v<<" : "<<(sum+=x.w)<<'\n';
    cout<<"MST cost = "<<sum<<'\n';
}
