#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5;
const ll len  =4*N;
ll arr[N],seg[len];
void build(ll idx,ll low,ll high)
{
    if(low == high){seg[idx] = arr[low];return;}
    ll mid = (low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}
ll query(ll idx,ll low,ll high,ll l ,ll r)
{
    if(l>r) return INT_MAX;
    if(l == low && r == high) return seg[idx];
    if(low > r || high < l )return INT_MAX;
    ll mid = (low + high) /2;
    ll left = query(2*idx+1,low,mid,l,min(r,mid));
    ll right = query(2*idx+2,mid+1,high,max(l,mid+1),r);
    return min(left,right);
}
void update(ll idx,ll low,ll high,ll node,ll val)
{
    if(low == high){seg[idx] =val;return;}
    else 
    {
        ll mid = (low+high)/2;
        if(node<=mid)update(2*idx+1,low,mid,node,val);
        else update(2*idx+2,mid+1,high,node,val);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++){cin>>arr[i];}
    build(0,0,n-1);
    while(q--)
    {
        ll t,a,b;
        cin>>t>>a>>b;
        a--;
        if(t==1)
        {
            update(0,0,n-1,a,b);
        }
        else {
            b--;
            cout<<query(0,0,n-1,a,b)<<endl;
        }
    }
    return  0;
}