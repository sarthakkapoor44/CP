#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll> > > adj(n),adjt(n);
    for(int i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a-1].push_back({b-1,w});
        adjt[b-1].push_back({a-1,w});
    }
    vector<ll> dist1(n,INF),dist2(n,INF);
    set<ll> min_dist;
    priority_queue<pair<ll,ll> , vector<pair<ll,ll> > ,greater<pair<ll,ll> > >pq;

    dist1[0]=0;
    vector<ll> vis1(n,0),vis2(n,0);
    pq.push({0,0});
    while(!pq.empty())
    {
        ll dist = pq.top().first;
        ll pos = pq.top().second;
        vis1[pos]=1;
        pq.pop();
        if(dist>dist1[pos])continue;
        for(auto x:adj[pos])
        {
            if(!vis1[x.first])
            {
                if(dist1[x.first]>dist1[pos]+x.second)
                {
                    dist1[x.first] =dist1[pos]+x.second;
                    pq.push({dist1[x.first],x.first});
                }
            }
        }
    }

    dist2[n-1]=0;
    pq.push({n-1,0});
    while(!pq.empty())
    {
        ll dist = pq.top().first;
        ll pos = pq.top().second;
        vis2[pos]=1;
        pq.pop();
        if(dist>dist2[pos])continue;
        for(auto x:adj[pos])
        {
            if(!vis2[x.first])
            {
                if(dist2[x.first]>dist2[pos]+x.second)
                {
                    dist2[x.first] =dist2[pos]+x.second;
                    pq.push({dist2[x.first],x.first});
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        
    }

}