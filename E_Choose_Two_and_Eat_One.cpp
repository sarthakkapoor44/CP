#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll b,ll m)
{   
    a%=m;
    ll res=1;
    while(b>0)
    {
        if(b&1)(res*=a%m)%=m;
        b>>=1;
        (a*=a%m)%=m;
    }
    return res;
}

vector<ll> parent,ranks;

void make_set(ll &a)
{
    parent[a] =a;
    ranks[a]=1;
    return ;
}

ll find_set(ll a)
{
    if(a==parent[a])return a;
    return parent[a] = find_set(parent[a]);
}


void union_set(ll a,ll b)
{
    a = find_set(a);
    b = find_set(b);
    if(ranks[a]<ranks[b])swap(a,b);
    ranks[a]+=ranks[b];
    parent[b]=a;
    return;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
    vector<vector<ll>> edges;
    parent.resize(n);
    ranks.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll a = arr[i];
            ll b = arr[j];
            ll val =  (binpow(a,b,m) + binpow(b,a,m))%m;
            edges.push_back({-val,i,j});
        }
    }

    for(ll i=0;i<n;i++)make_set(i);
    sort(edges.begin(),edges.end());
    ll ans  =0;
    for(int i=0;i<edges.size();i++)
    {
        ll a  = edges[i][2];
        ll b  = edges[i][1];
        ll w  = edges[i][0];
        if(find_set(a)!=find_set(b))
        {
            ans+= (-w);
            union_set(a,b);
        }
    }
    cout<<ans;
    return 0;
}