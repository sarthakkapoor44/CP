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
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll mod_inverse(ll a, ll m) {
    return binpow(a, m - 2, m);
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<pll> arr(n);  
   
        ll num_divisors = 1;
        vll prods_pref(n,1),prods_suf(n,1);
        rep(i,n)
        {
            cin>>arr[i].fi>>arr[i].se;
            (num_divisors*=(arr[i].se+1)%MODN)%=MODN;
            prods_pref[i] = ((arr[i].se+1)*(i?prods_pref[i-1]:1))%(MODN-1);
        }
        for(int i =n-1;i>=0;i--)
        {
            prods_suf[i] = ((arr[i].se+1)*(i<n-1?prods_suf[i+1]:1))%(MODN-1);
        }
        ll sum =1;
        rep(i,n){
            sum*= ((binpow(arr[i].fi,arr[i].se+1,MODN)-1)%MODN)*mod_inverse(arr[i].fi-1,MODN)%MODN;
            sum%=MODN;
        }
        ll prod_divisors = 1;
        rep(i,n){
            ll num=1;
            if(i)num = prods_pref[i-1]%(MODN-1);
            if(i<n-1)num = (num*prods_suf[i+1])%(MODN-1);
            ll val  =(arr[i].se*(arr[i].se+1)/2)%(MODN-1);
            num = (num*val)%(MODN-1);
            prod_divisors *= (binpow(arr[i].fi,num,MODN))%MODN;
            prod_divisors %= MODN;
        }
        cout<<num_divisors<<" "<<sum<<" "<<prod_divisors<<endl;
    }

    return 0;
}
