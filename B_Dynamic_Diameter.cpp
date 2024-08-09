#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<vector<ll> > adj;
vector<ll> mx_dist;
ll max_distance;
void dfs1(ll pos,ll parent,ll dist,ll &node)
{   
    if(dist>max_distance){max_distance=dist;node = pos;}
    for(auto x:adj[pos])
    {
        if(x==parent)continue;
        dfs1(x,pos,dist+1,node);
    }

}
void dfs2(ll pos,ll parent,ll dist)
{
    mx_dist[pos] = max(dist,mx_dist[pos]);
    for(auto x:adj[pos])
    {
        if(x==parent)continue;
        dfs2(x,pos,dist+1);
    }

}
int main()
{
    ll n ;cin>>n;
    adj.clear();
    adj.resize(n);
    for(int i=0;i<n-1;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    mx_dist.clear();
    mx_dist.resize(n);
    ll a=-1,b=-1;
    max_distance = 0;
    dfs1(0ll,-1ll,0ll,a);
    max_distance = 0;
    if(a!=-1)dfs1(a,-1ll,0ll,b);
    if(a!=-1)dfs2(a,-1,0);
    if(a!=-1)dfs2(b,-1,0);

    ll dia =*max_element(mx_dist.begin(),mx_dist.end());
    // for(auto x:mx_dist)cout<<x<<" ";
    for(int i=0;i<n;i++)
    {
        if(mx_dist[i]==dia){cout<<dia+1<<" ";}
        else cout<<dia<<" ";
        cout<<endl;
    }
    
}