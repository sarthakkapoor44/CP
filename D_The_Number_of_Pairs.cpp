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
const ll MAXN = 20000001;
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


ll modmul(ll a, ll b, ll M) 
{
    ll ret = a * b - M * ll(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ll modpow(ll b, ll e, ll mod) 
{
    ll ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
    if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ll n) 
{
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ll A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } ,
    s = __builtin_ctzll(n-1), d = n >> s;
    for (ll a : A) 
    { 
        ll p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
        p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

ll pollard(ll n) 
{
    ll x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ll x) { return modmul(x, x, n) + i; } ;
    while (t++ % 40 || __gcd(prd, n) == 1) 
    {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
unordered_map<ll, ll> cnt;
vector<ll> factor(ll n) 
{
    if (n == 1) return { } ;
    if (isPrime(n)) 
    {
        if(cnt[n]==0) 
        {
            cnt[n]++;
            return { n } ;
        }
       else return { } ;
    }
    ll x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

vector<int> fact_cnt(MAXN);
vector<int> lp(MAXN+1);
vector<int> pr;

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    for (int i=2; i < MAXN; ++i) 
    {
        if (lp[i] == 0) {
            lp[i] = i;
            fact_cnt[i] = 1;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] < MAXN; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    for(int i=2; i < MAXN; ++i) 
    {
        if(fact_cnt[i]==1)continue;
        ll spf = lp[i];
        ll num = i/spf;
        fact_cnt[i] = fact_cnt[num];
        if(num%spf!=0)fact_cnt[i]++;
    }
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll c,d,x;
        cin>>c>>d>>x;;         
        vector<ll> s;
        ll ans =0 ;
        for(ll i = 1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                if(i!=(x/i))s.pb(i);
                s.pb(x/i);
            }
        }
        for(auto y:s)
        {
            if(((x/y)+d)%c==0)
            {
                ll prod = ((x/y)+d)/c;
                ans+= (1ll<<fact_cnt[prod]);
            }
        }
        cout<<ans;ce;

    }

    return 0;
}