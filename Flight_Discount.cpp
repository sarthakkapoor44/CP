#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int> > > adj(n),adjt(n);
    for(int i=0;i<m;i++)
    {
        int a,b;ll w;cin>>a>>b>>w;
        adj[a-1].push_back({b-1,w});
        adjt[b-1].push_back({a-1,w});
    }
    priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
    pq.push({0,0});
    vector<bool> vis1(n,0),vis2(n,0);
    vector<ll> dist1(n,INF),dist2(n,INF);
    dist1[0]=0; dist2[n-1]=0;
    while(!pq.empty())
    {
        ll val = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        vis1[u] = 1;

        if(dist1[u]< val)continue;

        for(auto x:adj[u])
        {   
            int v =  x.first;
            ll w = x.second;
            if(!vis1[v] && dist1[v] >dist1[u]+w )
            {
                dist1[v] =dist1[u]+w;
                pq.push({dist1[v],v});
            }
        }
    }
    pq.push({0,n-1});
    while(!pq.empty())
    {
        ll val = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        vis2[u] = 1;

        if(dist2[u]< val)continue;

        for(auto x:adjt[u])
        {   
            int v =  x.first;
            ll w = x.second;
            if(!vis2[v] && dist2[v] >dist2[u]+w )
            {
                dist2[v] =dist2[u]+w;
                pq.push({dist2[v],v});
            }
        }
    }
    ll min_path =INF;
    for(int i=0;i<n;i++)
    {
        for(auto x: adj[i])
        {
            ll w= x.second;
            min_path = min(min_path,dist1[i]+w/2+dist2[x.first]);
        }
    }
    cout<<min_path;

    return 0;
}