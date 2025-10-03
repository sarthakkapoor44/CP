///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
   tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
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
        ll n;
        cin>>n;
        vector<pair<ll,ll>> arr(n);
        rep(i,n)cin>>arr[i].fi>>arr[i].se; 
        vector<ll> ans(n);
        vector<pair<pair<ll,ll>,ll>> a,b;
        map<pair<ll,ll>,ll> cnt;
        rep(i,n)
        {
            cnt[arr[i]]++;
        }
        rep(i,n)
        {
        
            a.pb({arr[i],i});
            b.pb({arr[i],i});
            
        }
        sort(a.begin(),a.end(),[&](pair<pair<ll,ll>,ll> i,pair<pair<ll,ll>,ll> j)->bool{
            if(i.fi.fi == j.fi.fi)return i.fi.se > j.fi.se;
            return i.fi.fi < j.fi.fi;
        });
        sort(b.begin(),b.end(),[&](pair<pair<ll,ll>,ll> i,pair<pair<ll,ll>,ll> j)->bool{
            if(i.fi.se == j.fi.se)return i.fi.fi > j.fi.fi;
            return i.fi.se < j.fi.se;});
        
        
        multiset<ll> pos;
        for(int i = 0 ; i < a.size() ; i++)
        {
            auto x = pos.lower_bound(a[i].fi.se);
            ll idx = 0 ;
            if(pos.size() && x!=pos.end()){idx = *x-a[i].fi.se;}
            ans[a[i].se]+=idx;
            pos.insert(a[i].fi.se);
            // debug(idx,pos);
        }
        pos.clear();
        for(int i = b.size()-1; i >= 0; i--)
        {
            auto x = pos.upper_bound(b[i].fi.fi);
            ll idx = 0 ;
            if(pos.size() && x!=pos.begin()){x--;idx = abs(*x-b[i].fi.fi);}
            ans[b[i].se]+=idx;
            pos.insert(b[i].fi.fi);
            // debug(idx,pos);
        }
        rep(i,n)if(cnt[arr[i]]>1)ans[i]= 0;
        rep(i,n)cout<<ans[i]<<endl;
        // debug(a,b);
    }

    return 0;
}
