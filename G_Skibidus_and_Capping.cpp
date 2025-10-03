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


ll modmul(ll a, ll b, ll M) {
    ll ret = a * b - M * ll(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ll modpow(ll b, ll e, ll mod) {
    ll ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

const int LIM = 1000000;
bitset<LIM> primeBits;

vector<int> eratosthenes() 
{
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vector<int> pr = {2}, sieve(S+1);
    pr.reserve(int(LIM/log(LIM) * 1.1));
    vector<pair<int,int>> cp;
    for (int i = 3; i <= S; i += 2) {
        if (!sieve[i]) {
            cp.push_back({i, i * i / 2});
            for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
        }
    }
    for (int L = 1; L <= R; L += S) {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = true;
        for (int i = 0; i < min(S, R - L); i++)
            if (!block[i]) pr.push_back((L + i) * 2 + 1);
    }
    for (int i : pr) primeBits[i] = true;
    return pr;
}

bool isPrime(ll n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (ll a : A) {
        ll p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return false;
    }
    return true;
}

ll pollard(ll n) {
    ll x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ll x) { return modmul(x, x, n) + i; };
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

vector<ll> factor(ll n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ll x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
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
        vll arr(n);
        rep(i,n)cin>>arr[i];
        srt(arr);
        
        vector<ll> cnt(n+1);
        ll ss = 0,dd = 0;
        ll ans = 0 ;
        // vector<vector<ll>> fact(n);
        rep(i,n)
        {
            vector<ll> primes = factor(arr[i]);
            if(primes.size()==1)
            {
                ans+= ss;
                ans -= cnt[arr[i]];
                ss++;
                cnt[arr[i]]++;
            }
            else if(primes.size()==2)
            {
                ans++;
                ans+= cnt[arr[i]];
                cnt[arr[i]]++;
                ll pr1 = primes[0];
                ll pr2 = primes[1];
                ans += cnt[pr1];
                if(pr1!=pr2)ans+=cnt[pr2];
            }
            
        }
        cout<<ans<<endl;
    }

    return 0;
}
