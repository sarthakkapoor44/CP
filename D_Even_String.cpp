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
const ll MAXN = 500000+5;
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
ll mod_inverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
vector<ll> factorial(MAXN);
void precompute_factorials() {
    factorial[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        factorial[i] = (factorial[i - 1] * i) % modn;
    }
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    precompute_factorials(); // Precompute factorials up to MAXN
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll len =0 ;
        vector<ll> a(26);
        rep(i,26){ cin>>a[i]; len+=a[i];}
        ll odd_len = (len+1)/2;
        ll even_len = len/2;
        vector<ll> dp(len+1,0);
        dp[0] =1;
        ll ans =1;
        rep(i,26)
        {
            if(a[i]==0) continue;
            for(ll j =len;j>=a[i];j--)
            {
                dp[j] += (dp[j-a[i]])%modn;
            }
            if(a[i]>1)(ans*= mod_inverse(factorial[a[i]],modn)%modn)%=modn;
            // debug(a[i],ans,factorial[a[i]]);
        }
        (ans*= (factorial[odd_len]*factorial[even_len])%modn)%=modn;
        (ans*=dp[odd_len]%modn)%=modn;
        cout<<ans%modn<<endl;
    }

    return 0;
}
