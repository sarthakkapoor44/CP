#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200001;
vector<vector<ll> > adj;
vector<ll> dp1(N,-1),dp2(N,-1);
vector<ll> max_dist(N);
// dp1 for children
// dp2 for parent 
void dfs1(ll pos,ll parent)
{
    if(adj[pos].size()==1 && parent!=-1)
    {
        dp1[pos]=0;
        return;
    }
    if(dp1[pos]!=-1)return;
    for(auto x:adj[pos])
    {
        if(x== parent)continue;
        dfs1(x,pos);
        dp1[pos] = max(dp1[x]+1,dp1[pos]);
    }
    return ;
}
void dfs2(ll pos , ll parent)
{
    if(adj[pos].size()==1 && parent!=-1)return;
    vector<ll> temp;
    for(auto x:adj[pos])
    {
        if(x!=parent)
        {
            temp.push_back(dp1[x]);
        }
    }
    sort(temp.begin(),temp.end());
    for(auto x:adj[pos])
    {

        if(x!=parent)
        {
            dp2[x]=dp2[pos]+1;
            auto y = lower_bound(temp.begin(),temp.end(),dp1[x]);
            if(y!=(--temp.end())){dp2[x]= max(dp2[pos]+1,2+*(--temp.end()));}
            else 
            {
                if(y!=temp.begin())
                {
                    y--;
                    dp2[x]= max(dp2[pos]+1,2+*y);
                }
            }  
        dfs2(x,pos); 
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    adj.clear();
    adj.resize(n);
    for(int i=0;i<n-1;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    if(n==1)cout<<0<<" ";
    else
    {
        dp2[0]=0;
        dfs1(0,-1);
        dfs2(0,-1);
        for(int i=0;i<n;i++)cout<<max(dp1[i],dp2[i])<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<dp2[i]<<" ";

    }
    cout<<endl;
}