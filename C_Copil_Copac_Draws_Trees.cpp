#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N  = 200001;
vector<vector<pair<ll,ll> > > adj;
vector<ll> dp(N,0);
ll ans =1;
void dfs(ll pos, ll parent,ll edge)
{
    // if(dp[pos] && parent!=-1) return;
    for(auto x:adj[pos])
    {
        if(x.first== parent)continue;
        if(x.second> edge) dp[x.first] = dp[pos];
        else 
        { 
            dp[x.first] =  dp[pos]+1;
            ans = max(ans,dp[x.first]);
        }
        dfs(x.first,pos,x.second);
    }
    
    return; 
}
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        adj.clear();
        adj.resize(n);
        for(int i=0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u-1].push_back(make_pair(v-1,i+1));
            adj[v-1].push_back(make_pair(u-1,i+1));
        }
        dp[0]=1;
        dfs(0,-1,0);
        cout<<ans<<endl;
        ans=1;
    }
    return 0;
}