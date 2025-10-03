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
#define pll pair<ll,ll>
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
const ll MAXN = 5e5+5;
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


int t[4*MAXN];

void build(vector<ll>&a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}

ll getMin(int v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return INF;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return min(getMin(v*2, tl, tm, l, min(r, tm)),getMin(v*2+1, tm+1, tr, max(l, tm+1), r));
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
        vector<ll> arr(n);
        rep(i,n)cin>>arr[i];
        vector<pair<ll,ll>> idx(n,{0,n+1});
        stack<ll> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i])st.pop();
            if(!st.empty())idx[i].fi =st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            if(!st.empty())idx[i].se =st.top()+1;
            st.push(i);
        }
        srt(idx);
        // debug(idx);
        vector<ll> idxGreater(n);
        rep(i,n)idxGreater[i] = idx[i].se;
        build(idxGreater,1,0,n-1);
        rep(i,q){
            ll l,r;
            cin>>l>>r;
            auto litr = lower_bound(all(idx),make_pair(l,-INF))-idx.begin();
            auto ritr = min(n-1,ll(lower_bound(all(idx),make_pair(r,-INF))-idx.begin()));
            ll mn = getMin(1,0,n-1,litr,ritr);
            // debug(litr,ritr,mn);
            if(mn <= r)pno;
            else pyes;
            ce;
        }
         
        
    }

    return 0;
}