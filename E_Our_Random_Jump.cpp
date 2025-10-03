///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#include<iomanip>
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
//B87678 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll a,b;
        cin>>a>>b;
        vector<ll> points(a),ports(b);
        rep(i,a)cin>>points[i];
        rep(i,b)cin>>ports[i];
        vector<ll>cnt(n+1),nc(n+1);
        rep(i,b)cnt[ports[i]]=1;
        rep(i,a)nc[points[i]]=1;
        // dp[n]={1,0};
        // debug(points,ports);
        long double p =1,num = 0;
        long double finp =0 ,finNum =0;
        for(int i=n-1;i>=1;i--){
            if(nc[i])continue;
            ll denom= n-i;
            if(i == 1){
                finp = (long double)(p/denom);
                finNum = (long double)(num/denom);
            } 
            if(!cnt[i]){
                num += (long double)(num/denom);
                p += (long double)(p/denom);
            }
            else if(cnt[i]){num += cnt[i]; }
            // debug(p,num,i);
        }
        // debug(finNum,finp);
        long double ans = (long double)(finNum/(1-finp));
        cout<<fixed<<setprecision(6)<<ans;ce;
    }

    return 0;
}
