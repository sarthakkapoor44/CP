#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent,sizes;
void make_set(ll i)
{
    sizes[i]=1;
    parent[i]=i;
}
int find_set(ll i){
    if(i== parent[i])return i;
    return parent[i]=find_set(parent[i]);
}
void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(sizes[a]<sizes[b]){swap(a,b);}
        sizes[a]+=sizes[b];
        parent[b]=a;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll> > > edges;
    for(int i=0;i<m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        a--;b--;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    parent.resize(n);
    sizes.resize(n);
    ll cost =0;
    ll cnt = 0;
    for(int i=0;i<n;i++)make_set(i);
    for(int i=0;i<m;i++)
    {
        ll w = edges[i].first;
        ll a = edges[i].second.first;
        ll b = edges[i].second.second;
        if(find_set(a)!=find_set(b))
        {
            cost+=w;
            union_set(a,b);
            cnt++;
        }
    }
    if(cnt !=n-1)cout<<"IMPOSSIBLE";
    else cout<<cost;
    return 0;
}