#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+1;
const ll MODN = 1e9+7;
vector<vector<ll> > adj(N);
vector<ll> dp1(N,1),dp2(N,1);
void indSet(ll pos,ll parent)
{
    if(dp1[pos]>1 && dp2[pos]>1)return;
    if(adj[pos].size()== 1 && parent!=-1){dp1[pos]=1;dp2[pos]=1;return;}
    for(auto x:adj[pos])
    {
        if(x==parent)continue;
        indSet(x,pos);
        (dp1[pos]*=((dp2[x]+dp1[x])%MODN)%MODN)%=MODN;
    }
    
    for(auto x: adj[pos])
    {
        if(x==parent)continue;
        (dp2[pos]*=dp1[x]%MODN)%=MODN;
    }
    return ;
}
int main()
{
    ll n;cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    indSet(0,-1);
    cout<<(dp1[0]+dp2[0])%MODN;
}