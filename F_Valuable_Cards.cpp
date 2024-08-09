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

vector<ll> getFactors(ll n) {
    vector<ll> factors;
    for (ll i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            factors.push_back(i); 
            if (i != n / i) {
                factors.push_back(n / i); 
            }
        }
    }
    return factors;
}

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n, k;cin >> n >> k;vll a(n);
        rep(i,n)cin>>a[i];
        ll sum  =0;rep(i,n){sum+=1;}ll segments = 1;
        vll factors = getFactors(k);
        map<ll, ll> factor_map_current, factor_map_next;
        for (auto factor : factors) {factor_map_current[factor] = 0;factor_map_next[factor] = 0;}
        set<ll> current_factors;
        current_factors.insert(1);
        for (auto value : a) {
            if (k % value != 0) continue;
            if (factor_map_next[k / value]) {
                segments++;factor_map_next = factor_map_current;factor_map_next[value] = 1;current_factors.clear();current_factors.insert(1);current_factors.insert(value);
                continue;
            }
            set<ll> temp_factors;
            for (auto factor : current_factors) {
                if (factor_map_current.find(factor * value) != factor_map_current.end()) {factor_map_next[factor * value] = 1;temp_factors.insert(factor * value);}
            }
            for (auto factor : temp_factors) {current_factors.insert(factor);}current_factors.insert(value);
        }
            cout<<segments<< endl;

        }

    return 0;
}

