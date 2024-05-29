#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> topo ;
vector<vector<ll> > adj;
bool toposort(ll pos,vector<int> &vis)
{   
    vis[pos]=1;
    for(auto x: adj[pos])
    {
        if(!vis[x]){if(toposort(x,vis))return true;}
        else if(vis[x]==1){return true;}
    }
    topo.push_back(pos);
    vis[pos]=2;
    return false;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    adj.resize(n);
    topo.clear();
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
    }
    vector<int> vis(n,0);
    bool flag=0;
    for(int i=0;i<n;i++)if(!vis[i])if(toposort(i ,vis)){flag=1;break;}
    if(flag)cout<<"IMPOSSIBLE";
    else
    {
        reverse(topo.begin(),topo.end());
        for(auto x:topo)cout<<x+1<<" ";

    }

}