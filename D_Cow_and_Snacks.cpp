#include<bits/stdc++.h>
using namespace std;
void dfs(int pos,vector<set<int> > &adj,vector<int> &visited,int &len)
{
    if(!visited[pos])
    {

        // cout<<pos+1<<endl;
        visited[pos]=1;
        for(auto x:adj[pos])
        {
            if(!visited[x]){len++;dfs(x,adj,visited,len);}
        }
    }
}
bool cycle(int pos,int parent,vector<set<int> > &adj,vector<int> &visited)
{
    visited[pos]=1;
    for(auto x:adj[pos])
    {
        if(visited[x] && x!=parent) return true;
        if(!visited[x])
        {
           if(cycle(x,pos,adj,visited)) return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<set<int> > adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);

    }
    int len  =0;
    vector<int> visited(n,0),visited2(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && adj[i].size())
            {
                // cout<<i+1<<"->"<<len<<" ";
                dfs(i,adj,visited,len);
                // if(cycle(i,-1,adj,visited2)){len--;}
                // cout<<len<<endl;
            }
    }
    cout<<m-len<<endl;
}