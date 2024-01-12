#include<bits/stdc++.h>
using namespace std;
void dfs(int n,unordered_map<int,bool> &visited,   unordered_map<int, vector<int> > adj){
    visited[n]=true;
    cout<<n<<" ";
    for(auto x:adj[n]){
        if(!visited[x]){
            dfs(x,visited,adj);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int, vector<int> > adj;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
}

unordered_map<int,bool> visited(n);

for(int i=0;i<n;i++){
 if(!visited[i]){
 dfs(i,visited,adj);
 cout<<endl;
 }

}
    return 0;

}