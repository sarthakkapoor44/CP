#include<bits/stdc++.h>
#include<list>
using namespace std;
template <typename T>
class graph{
public: 
    unordered_map<T,list<T> > adj;
    void addEdge(T u,T v,bool direction ){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(v);
        }
    }
    void printGraph(){
        for(auto i : adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<" ,";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    graph<int> g;
    cout<<"enter the number of edges"<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
    g.addEdge(u,v,0);
    }
    g.printGraph();
    return 0;
    }