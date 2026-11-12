// Q18 AIM: BFS/DFS on specified 0..5 graph; PDF omits start, example starts at 0.
#include <iostream>
#include <queue>
using namespace std;
int g[6][6]{
};
bool seen[6];
void dfs(int u){
    seen[u]=1;
    cout<<u<<' ';
    for(int v=0;v<6;v++)if(g[u][v]&&!seen[v])dfs(v);
}
int main(){
    int e[][2]={
        {
            0,1
        },{
            0,2
        },{
            1,3
        },{
            1,4
        },{
            2,4
        },{
            3,5
        },{
            4,5
        }
    };
    for(auto&x:e)g[x[0]][x[1]]=g[x[1]][x[0]]=1;
    bool v[6]={
    };
    queue<int>q;
    q.push(0);
    v[0]=1;
    cout<<"BFS: ";
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<' ';
        for(int w=0;w<6;w++)if(g[u][w]&&!v[w])v[w]=1,q.push(w);
    }
    cout<<"\nDFS: ";
    dfs(0);
    cout<<'\n';
}
