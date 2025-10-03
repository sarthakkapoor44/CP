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
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);
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
const ll MAXN = 200000 +5;
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
// ans,min,max
ll seg[4*MAXN][3],seg2[4*MAXN][3];
void build(ll v,ll tl,ll tr,vll &arr,vll &arr2)
{
    if(tl == tr)
    {
        seg[v][1] = arr[tl];
        seg[v][2] = arr[tl];
        seg[v][0] = 0;

        seg2[v][1] = arr2[tl];
        seg2[v][2] = arr2[tl];
        seg2[v][0] = 0;

        return;
    }
    ll tm = (tl+tr)/2;
    build(2*v,tl,tm,arr,arr2);
    build(2*v+1,tm+1,tr,arr,arr2);
    seg[v][1] = min(seg[2*v][1],seg[2*v+1][1]); 
    seg[v][2] = max(seg[2*v][2],seg[2*v+1][2]); 
    seg[v][0] = max(seg[2*v][0],seg[2*v+1][0]);
    seg[v][0] = max(seg[v][0],seg[2*v+1][2] - seg[2*v][1]);

    seg2[v][1] = min(seg2[2*v][1],seg2[2*v+1][1]); 
    seg2[v][2] = max(seg2[2*v][2],seg2[2*v+1][2]); 
    seg2[v][0] = max(seg2[2*v][0],seg2[2*v+1][0]);
    seg2[v][0] = max(seg2[v][0],seg2[2*v][2] - seg2[2*v+1][1]);
    return;
}
void update(ll v,ll tl,ll tr, vll &arr,vll &arr2, ll idx,ll val)
{
    if(tl == tr)
    {
        arr[idx] = val - (idx+1);
        seg[v][1] = arr[tl];
        seg[v][2] = arr[tl];
        seg[v][0] = 0;

        arr2[idx] = val + (idx+1);
        seg2[v][1] = arr2[tl];
        seg2[v][2] = arr2[tl];
        seg2[v][0] = 0;

        return;
    }
    ll tm = (tl+tr)/2;
    if(idx <= tm)
    {
        update(2*v,tl,tm,arr,arr2,idx,val);
    }
    else
    {
        update(2*v+1,tm+1,tr,arr,arr2,idx,val);
    }
    seg[v][1] = min(seg[2*v][1],seg[2*v+1][1]); 
    seg[v][2] = max(seg[2*v][2],seg[2*v+1][2]); 
    seg[v][0] = max(seg[2*v][0],seg[2*v+1][0]);
    seg[v][0] = max(seg[v][0],seg[2*v+1][2] - seg[2*v][1]);
    
    seg2[v][1] = min(seg2[2*v][1],seg2[2*v+1][1]); 
    seg2[v][2] = max(seg2[2*v][2],seg2[2*v+1][2]); 
    seg2[v][0] = max(seg2[2*v][0],seg2[2*v+1][0]);
    seg2[v][0] = max(seg2[v][0],seg2[2*v][2] - seg2[2*v+1][1]);
    return;

}


int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        vll arr(n),arr2(n);
        rep(i,n)
        {
            cin>>arr[i];
            arr[i] -=(i+1);
            arr2[i] = arr[i]+ 2*(i+1);
        }
        // out(arr);
        build(1,0,n-1,arr,arr2);
        cout<<max(seg[1][0],seg2[1][0])<<endl;
        rep(i,q)
        {
            ll a,b;
            cin>>a>>b;
            a--;
            update(1,0,n-1,arr,arr2,a,b);
            cout<<max(seg[1][0],seg2[1][0])<<endl;
        }
        
    }

    return 0;
}
