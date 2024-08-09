#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n),adjt(n);
    for(ll i= 0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adjt[b-1].push_back(a-1);
    }
    vector<ll> tout;
    vector<ll> vis(n,0),vis2(n,0);
    function<void(ll)> dfs1  = [&](ll pos)->void{
        vis[pos]=1;
        for(auto x:adj[pos])
        {
            if(!vis[x])
            {
                dfs1(x);
            }
        }
        tout.push_back(pos);
    };
    for(ll i= 0;i<n;i++)if(!vis[i])dfs1(i);
    reverse(tout.begin(),tout.end());

    vector<ll> components(n,0);
    ll num_comp = 0;

    function<void(ll)> dfs2  = [&](ll pos)->void{
        vis2[pos]=1;
        components[pos] = num_comp;
        for(auto x:adjt[pos])
        {
            if(!vis2[x])
            {
                dfs2(x);
            }
        }
    };

    for(auto x:tout)
    {
        if(!vis2[x]){num_comp++;dfs2(x);}
    }

    cout<<num_comp<<endl;
    for(auto x: components)cout<<x<<" ";
    
    return 0;
}