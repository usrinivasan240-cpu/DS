// Q8 AIM: Min heap with insertion, display and delete-min. Input values are not specified in PDF.
#include <iostream>
#include <vector>
using namespace std;
class Heap{vector<int>a;public:void insert(int x){a.push_back(x);int i=a.size()-1;while(i&&a[(i-1)/2]>a[i])swap(a[i],a[(i-1)/2]),i=(i-1)/2;}void del(){if(a.empty()){cout<<"Heap empty\n";return;}cout<<"Deleted "<<a[0]<<'\n';a[0]=a.back();a.pop_back();int i=0;while(2*i+1<(int)a.size()){int c=2*i+1;if(c+1<(int)a.size()&&a[c+1]<a[c])c++;if(a[i]<=a[c])break;swap(a[i],a[c]);i=c;}}void show(){for(int x:a)cout<<x<<' ';cout<<'\n';}};
int main(){Heap h;int n,x;cin>>n;while(n--){cin>>x;h.insert(x);}cout<<"Heap: ";h.show();h.del();cout<<"Updated: ";h.show();}