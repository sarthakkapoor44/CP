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
        string text,pat;
        cin>> text>>pat;
        ll p = 53;
        ll modn = 1e9+7;
        ll T = text.length();
        ll P = pat.length();
        vector<ll> power(max(T,P)+1,1);
        for(ll i=1;i<=max(T,P);i++)
        {
            power[i]  = (power[i-1]*p)%modn;
        }
        ll hp = 0;
        for(ll i=0;i<P;i++)
        {
            hp = (hp+((pat[i]-'a'+1)*power[i])%modn)%modn;
        }
        vector<ll> h(T+1,0);
        for(ll i=0;i<T;i++)
        {
            h[i+1] = (h[i] + ((text[i]-'a'+1)*power[i])%modn)%modn; 
        }
        ll ans = 0;
        for(ll i= 0 ;i<T-P+1;i++)
        {
            ll current_hash = (h[i+P] - h[i] + modn)%modn;
            ll val = (hp*power[i])%modn;
            if(current_hash == val){ans++;}
        }
        cout<<ans;
        
    }

    return 0;
}
