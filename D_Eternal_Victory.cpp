#include<bits/stdc++.h>
typedef long long ll;

int main()
{
    ll n;
    std::cin>>n;
    std::vector<std::vector<std::pair<ll,ll>>> adj(n);
    ll sum =0;
    for(int i=0;i<n-1;i++)
    {
        ll a,b,w;
        std::cin>>a>>b>>w;
        a--;b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        sum += 2*w;
    }
    std::queue<ll> q;
    std::vector<ll> dist(n,-1);
    q.push(0);dist[0] =0;
    ll max_distance = 0;
    while(!(q.empty()))
    {
        ll u  = q.front();
        q.pop();
        for(auto x: adj[u])
        {
            ll v = x.first;
            ll edge_weight = x.second;
            if(dist[v]==-1)
            {
                dist[v]  =  dist[u]+ edge_weight;
                max_distance = std::max(max_distance,dist[v]);
                q.push(v);
            }
        }
    }
    std::cout<< sum - max_distance;
}
