///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 100001;
const ll modn = 998244353;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}

vector<pair<ll,ll>> seg(4*MAXN);
void build(ll v, ll tl , ll tr, vll &arr)
{
    if(tl == tr)
    {
        seg[v] = {arr[tl],1};
        return ;
    }
    ll mid = tl + (tr-tl)/2;
    build(2*v,tl,mid,arr);
    build(2*v+1,mid+1,tr,arr);
    seg[v].fi = min(seg[2*v].fi,seg[2*v+1].fi);

    if(seg[2*v].fi == seg[2*v+1].fi)
    {
        seg[v].se = seg[2*v].se + seg[2*v+1].se;
    }
    else if(seg[2*v].fi < seg[2*v+1].fi)
    {
        seg[v].se = seg[2*v].se;
    }
    else
    {
        seg[v].se = seg[2*v+1].se;
    }
    return;
}

void update(ll v, ll tl , ll tr,ll idx, ll val, vll&arr)
{   
    if(tl == tr)
    {
        arr[tl] = val;
        seg[v] = {arr[tl],1};
        return ;
    }
    ll mid = tl + (tr-tl)/2;
    if(idx > mid)
    {
        update(2*v+1,mid+1,tr,idx,val,arr);
    }
    else if(idx<=mid)
    {
        update(2*v,tl,mid,idx,val,arr);
    }
    seg[v].fi =  min(seg[2*v+1].fi,seg[2*v].fi);
    if(seg[2*v].fi > seg[2*v+1].fi)
    {
        seg[v].se = seg[2*v+1].se;
    }
    else if(seg[2*v].fi < seg[2*v+1].fi)
    {
        seg[v].se = seg[2*v].se;
    }
    else seg[v].se = seg[2*v].se +  seg[2*v+1].se;

    return ;
}
pair<ll,ll> query(ll v, ll l, ll r,ll tl, ll tr)
{
    if(l ==  tl and r == tr)
    {
        return seg[v];
    }

    ll mid = tl + (tr- tl)/2;

    if(l > mid)
    {
        return  query(2*v+1,l,r,mid+1,tr);
    }
    else if(r <= mid)
    {
        return query(2*v,l,r,tl,mid);
    }
    pair<ll,ll> p1 = query(2*v,l,mid,tl,mid),p2 = query(2*v+1,mid+1,r,mid+1,tr);
    if(p1.fi < p2.fi)
    {
        return p1;
    }
    else if(p1.fi > p2.fi)
    {
        return p2;
    }
    else
    {
        return {p1.fi,p1.se+p2.se};
    }
    
}

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    // cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vll arr(n+1);
        forf(i,1,n+1) cin>>arr[i];
        build(1,1,n,arr);
        rep(i,m)
        {
            ll type,a,b;
            cin>>type>>a>>b;    
            if(type == 1)
            {
                update(1,1,n,a+1,b,arr);
            }
            else
            {
                pair<ll,ll> ans = query(1,a+1,b,1,n);
                cout<<ans.fi<<" "<<ans.se<<endl;
            }
        }
        
    }

    return 0;
}
