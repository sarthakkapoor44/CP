#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a-1].push_back({b-1,w});
    }
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll>> ,greater<pair<ll,ll>>> pq;
    vector<priority_queue<ll>> dist(n);
    dist[0].push(0);
    pq.push({0,0});
    while(!pq.empty())
    {
        ll dist_top = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(dist[u].size()>=k && dist[u].top()<dist_top)continue;
        for(auto x: adj[u])
        {
            ll v = x.first;
            ll edge = x.second;
            ll dist_curr = dist_top + edge;
            if(dist[v].size()<k)
            {
                dist[v].push(dist_curr);
                pq.push({dist_curr,v});
            }
            else{
                if(dist_curr<dist[v].top())
                {
                    dist[v].pop();
                    dist[v].push(dist_curr);
                    pq.push({dist_curr,v});
                }
            }
        }
    }
    vector<ll> ans;
    while(dist[n-1].size()){ans.push_back(dist[n-1].top());dist[n-1].pop();}
    for(ll i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" "; 
    return 0;
}