#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ll n,m;cin>>n>>m;
    vector<ll> arr(n);for(int i=0;i<n;i++)cin>>arr[i];
    vector<vector<ll>> adj(n),adjt(n);
    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adjt[b-1].push_back(a-1);
    }
    vector<int> vis1(n),vis2(n),topo;
    function<void(int)> dfs1 = [&](int pos)->void{
        vis1[pos]=1;
        for(auto x:adj[pos])
        {
            if(!vis1[x])dfs1(x);
        }
        topo.push_back(pos);
    };
    for(int i=0;i<n;i++)if(!vis1[i])dfs1(i);
    reverse(topo.begin(),topo.end());
    vector<int> components(n,0);
    int num_comp  = 0 ;
    function<int(int)> dfs2 = [&](int pos)->int{
        vis2[pos]=1;
        components[pos] = num_comp;
        int temp  = arr[pos];
        for(auto x:adjt[pos])
        {
            if(!vis2[x])temp+= dfs2(x);
        }
        return temp;
    };

    vector<int> narr;
    for(auto x:topo)
    {
        int val = 0;
        if(!vis2[x])
        {
            val = dfs2(x);
            narr.push_back(val);
            num_comp++;
        }
    }

    function<void(int)> dfs3 = [&](int pos)->void{
        vis1[pos]=1;
        for(auto x:adj[pos])
        {
            if(!vis1[x])dfs1(x);
        }
        topo.push_back(pos);
    };
    

}