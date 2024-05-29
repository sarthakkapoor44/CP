#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200001;
#define INF 1000000000000000000
vector<vector<ll> > adj(N);
vector<ll> path(N,0);
ll ans  =0;
void calc_path(ll pos,ll parent)
{
    if (adj[pos].size()==1 && parent!=-1){path[pos]=0;return;}
    if(path[pos])return ;
    vector<ll> len;
    for(auto x:adj[pos])
    {
        if(x!=parent)
        {
            calc_path(x,pos);
            path[pos]= max(path[pos],path[x]+1);
            len.push_back(path[x]+1);
        }
    }
    sort(len.begin(),len.end());
    if(len.size())
    {
        ll val =len.back();
        len.pop_back();
        if(len.size()>=1)val+=len.back();
        ans= max(ans,val);
    }
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    calc_path(0,-1);
   
    cout<<ans;
}
