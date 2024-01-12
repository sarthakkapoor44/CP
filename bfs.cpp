#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int> > adj;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<int> q1;
    int start=0;
    q1.push(start);
    vector<int> ans;
    unordered_map<int,bool> visited(false);
    visited[0]=true;
    ans.push_back(0);
    while(!q1.empty()){
        int curr = q1.front();
    q1.pop();
        for(auto x:adj[curr])
        if(!visited[x]){
            visited[x]=true;
            q1.push(x);
            ans.push_back(x);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}