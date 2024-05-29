#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > edge_list;
    vector<vector<ll> > adj(n);
    for(int i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;b--;
        edge_list.push_back({a,b,-w});
        adj[b].push_back(a);
    }
    // sort(edge_list.begin(),edge_list.end());
    vector<ll> dist(n,INF);
    dist[0]=0;
    vector<ll> parent(n,-1);
    vector<bool> neg_edge(n);
    for(int i=0;i<n;i++)
    {
       
        for(auto x: edge_list)
        {
            ll a =x[0];
            ll b= x[1];
            ll w = x[2];
            if(dist[a]!=INF && dist[b]>dist[a]+w)
            {
                dist[b] = dist[a]+w;
                if(i==n-1)
                {
                    neg_edge[b]=1;
                }
            }
        }
    }
    queue<ll> q;
    q.push(n-1);
    bool flag=0;
    if(neg_edge[n-1])flag=1;
    vector<bool> vis(n,0);
    vis[n-1]=1;
    while(!q.empty())
    {
        ll pos = q.front();
        q.pop();
        for(auto x:adj[pos]){
            if(!vis[x])
            {
                vis[x]=1;
                if(neg_edge[x]){flag=1;break;}
                q.push(x);
            }
        }
    }
    if(flag)cout<<-1;
    else cout<<-dist[n-1];

}