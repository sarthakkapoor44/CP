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
#define pyes cout<<"YES";
#define pno cout<<"NO";
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
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vll arr1(n),arr2(n);
        ll mx = 0;
        rep(i,n){cin>>arr1[i];mx= max(mx,arr1[i]);}
        rep(i,n)cin>>arr2[i];
        vp vect(n);rep(i,n){vect[i] = {arr1[i]-arr2[i],arr1[i]};}
        vll dp (mx+1,INF);
        srt(vect);
        for(auto x:vect)
        {
            dp[x.se] = min(dp[x.se],x.fi); 
        }
        forf(i,0,mx+1)
        {
            if (i) dp[i] = min(dp[i],dp[i-1]);
        }
        vll dpp(mx+1);
        rep(i,mx+1)
        {
            if(dp[i]<INF) dpp[i] = 2 + dpp[i - dp[i]];
        }
        vll q(m);
        rep(i,m)cin>>q[i];
        ll ans = 0;
        for(auto x:q)
        {
            if(x>=mx)
            {
                ll k = ceil((x-mx)/(vect[0].fi*1.00));
                ans+= 2*k;
                x = x- k*vect[0].fi;
            }
            ans+= dpp[x];
        }
        cout<<ans;ce;
    }

    return 0;
}
