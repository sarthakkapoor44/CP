#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> topo;
bool check_cycle(ll pos,vector<vector<ll> > & adj,vector<int> & vis)
{
    vis[pos]=1;
    for(auto x:adj[pos])
    {
        if(!vis[x]){if(check_cycle(x,adj,vis))return true;}
        else if(vis[x]==1)return true;
        
    }
    topo.push_back(pos);
    vis[pos]=2;
    return false;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vector<vector<ll> > adj(n);
        topo.clear();
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++)
        {
            ll len;cin>>len;
            for(int j=0;j<len;j++)
            {
                ll val;
                cin>>val;
                adj[val-1].push_back(i);
                indeg[i]++;
            }
        }
        vector<int> vis(n,0);
        bool cycle=0;
        for(int i=0;i<n;i++){if(!vis[i]){if(check_cycle(i,adj,vis)){cycle=1;break;}}}
        ll ans=-1;
        if(!cycle)
        {
            ans=0;
            reverse(topo.begin(),topo.end());
            // for(auto x:topo)cout<<x<<" ";
            // cout<<endl;
            vector<ll> dp(n,0);
          
            for(int i=0;i<n;i++)
            {
                ll pos = topo[i];
                for(auto x:adj[pos])
                {
                    if(x<pos){dp[x]=max(dp[x],dp[pos]+1);}
                    else dp[x]= max(dp[x],dp[pos]);
                    ans=max(ans,dp[x]);
                }
            }
            // for(auto x:dp)cout<<x<<" ";
            ans++;
        }
        cout<<ans<<endl;
    }
}

