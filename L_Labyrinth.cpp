#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,s;
    cin>>n>>m>>s;
    s--;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    vector<ll> vis(n);
    vis[s]=1;
    vector<ll> parent(n,-1);

    ll target1 =-1,target2 =-1;
    ll l = ceil(log2(n));
    vector<vector<ll>> succ(n,vector<ll>(l+1,s));
    vector<ll> tin(n),tout(n);
    ll timer = 0;
    function<ll(ll,ll)> is_ancestor = [&](ll a,ll b)->ll{
        if(tin[a]<tin[b] && tout[a]>tout[b])return 1;
        return 0;
    };
    function<ll(ll,ll)> lca = [&](ll a,ll b)->ll{
        if(is_ancestor(a,b)){return a;}
        if(is_ancestor(b,a)){return b;}
        for(ll i=l;i>=0;i--)
        {
            if(!is_ancestor(succ[a][i],b))
            {
                a = succ[a][i];
            }
        }
        return succ[a][0];
    };
    vector<ll> vis2(n,0);
    function<void(ll,ll)> dfs1 = [&](ll pos,ll par)->void{
        succ[pos][0] = par;
        tin[pos]= ++timer;
        vis2[pos]=1;
        for(ll i=1;i<=l;i++)
        {
            succ[pos][i] = succ[succ[pos][i-1]][i-1];
        } 
        for(auto x:adj[pos])
        {
            if(!vis2[x])dfs1(x,pos);
        }
        tout[pos] = ++timer;
    };
    dfs1(s,s);
    function<void(ll,ll)> dfs = [&](ll pos,ll par)->void{
        if(target1>=0)return;
        vis[pos]=1;
        for(auto x: adj[pos])
        {
            if(vis[x]==2 && lca(x,pos)==s){
                target1 = x;
                target2 = pos;
                return;
            }
            else if(!vis[x])
            {
                parent[x]=pos;
                dfs(x,pos);
            }
        }
        vis[pos]=2;
        return;
    };
    dfs(s,s);
    if(target1>=0){
        cout<<"Possible";
        cout<<endl;
        ll ind  = target1;
        vector<ll> ans1,ans2;
        ans1.push_back(target1+1);
        while(parent[ind]!=-1){ans1.push_back(parent[ind]+1);ind = parent[ind];}
        ind  = target2;
        ans2.push_back(target1+1);
        ans2.push_back(target2+1);
        while(parent[ind]!=-1){ans2.push_back(parent[ind]+1);ind = parent[ind];} 
        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());
        cout<<ans1.size()<<endl;
        for(auto x:ans1)cout<<x<<" ";
        cout<<endl;
        cout<<ans2.size()<<endl;
        for(auto x:ans2)cout<<x<<" ";
    }
    else cout<<"Impossible";

    return 0;
}