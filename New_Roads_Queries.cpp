#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> sizez,parent;
void make_set(ll i)
{
    parent[i]=i;
    sizez[i]=1;
    return ;
}
ll find_set(ll i)
{
    if(parent[i]==i)return i;
    return parent[i] = find_set(parent[i]);
}
void union_set(ll a,ll b)
{
    a = find_set(a);
    b = find_set(b);
    if(sizez[a]<sizez[b])swap(a,b);
    sizez[a]+=sizez[b];
    parent[b]=a;
}
int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    ll num_components =n;
    ll max_size =1;
    sizez.clear();
    parent.clear();
    sizez.resize(n);
    parent.resize(n);
    for(ll i=0;i<n;i++){make_set(i);}
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;a--;b--;
        if(find_set(a)!=find_set(b))
        {
            num_components--;
            union_set(a,b);
            a= find_set(a);
            b= find_set(b);
            max_size  =max(max_size,max(sizez[a],sizez[b]));
        }
            cout<<num_components<<" "<<max_size<<endl;
    }
    return 0;
}