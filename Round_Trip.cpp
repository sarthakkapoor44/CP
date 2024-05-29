#include<bits/stdc++.h>
using namespace std;
int n,m;
int start=-1;
int last=-1;
bool dfs(int pos,int parent ,vector<vector<int> > &adj,vector<int> &vis,vector<int> &path)
{
    vis[pos]=1;
    for(auto x:adj[pos])
    {
        if(!vis[x])
        {
            path[x]=pos;
            if(dfs(x,pos,adj,vis,path))return true;
        }
        else if(x!=parent)
        { 
            start = x; 
            last = pos; 
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bool flag=  false;
    vector<int> vis(n,0);
    vector<int> path(n);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis,path))
            {
                flag=1;break;
            }
        }
    }

    // for(auto x: path)cout<<x<<" ";cout<<endl;
    
    int temp =last;
    vector<int> ans;
    if(flag)
    {
        while (last!=start)
        {
            ans.push_back(last+1);
            last = path[last];
        }
        ans.push_back(start+1);
        ans.push_back(temp+1);
        cout<<ans.size()<<endl;
        for(auto x: ans)cout<<x<<" ";
    }
    else
    { 
        cout<<"IMPOSSIBLE";
    }

}