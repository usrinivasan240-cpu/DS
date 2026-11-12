// Q2 AIM: Playlist with doubly linked list; insert at beginning/end/position, delete song, display both ways.
#include <iostream>
#include <string>
using namespace std;
struct N{
    string s;
    N*p,*n;
    N(string x):s(x),p(nullptr),n(nullptr){
    }
};
class Playlist{
    N*h=nullptr,*t=nullptr;
    int sz=0;
    public:~Playlist(){
        while(h){
            N*x=h;
            h=h->n;
            delete x;
        }
    }
    void insert(int pos,string s){
        if(pos<1||pos>sz+1){
            cout<<"Invalid position\n";
            return;
        }
        N*x=new N(s);
        if(pos==1){
            x->n=h;
            if(h)h->p=x;
            else t=x;
            h=x;
        }
        else{
            N*q=h;
            for(int i=1;i<pos-1;i++)q=q->n;
            x->n=q->n;
            x->p=q;
            if(q->n)q->n->p=x;
            else t=x;
            q->n=x;
        }
        sz++;
    }
    void append(string s){
        insert(sz+1,s);
    }
    void erase(string s){
        N*q=h;
        while(q&&q->s!=s)q=q->n;
        if(!q){
            cout<<"Not found\n";
            return;
        }
        if(q->p)q->p->n=q->n;
        else h=q->n;
        if(q->n)q->n->p=q->p;
        else t=q->p;
        delete q;
        sz--;
    }
    void forward(){
        for(N*q=h;q;q=q->n)cout<<q->s<<" <-> ";
        cout<<"NULL\n";
    }
    void backward(){
        for(N*q=t;q;q=q->p)cout<<q->s<<" <-> ";
        cout<<"NULL\n";
    }
};
int main(){
    Playlist p;
    int c,pos;
    string s;
    do{
        cout<<"1.Beginning 2.End 3.Position 4.Delete 5.Forward 6.Backward 0.Exit: ";
        cin>>c;
        if(c>=1&&c<=4){
            cout<<"Song: ";
            cin>>ws;
            getline(cin,s);
            if(c==1)p.insert(1,s);
            else if(c==2)p.append(s);
            else if(c==3){
                cout<<"Position: ";
                cin>>pos;
                p.insert(pos,s);
            }
            else p.erase(s);
        }
        else if(c==5)p.forward();
        else if(c==6)p.backward();
    }
    while(c);
}
