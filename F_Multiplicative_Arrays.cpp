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
 
// const ll MODN = 1e9 + 7;
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

bool isPrime(ll n) {
if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
ll A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } ,
s = __builtin_ctzll(n-1), d = n >> s;
for (ll a : A) { //^ count t r a i l i n g zeroes
ll p = modpow(a%n, d, n), i = s;
while (p != 1 && p != n - 1 && a % n && i--)
p = modmul(p, p, n);
if (p != n-1 && i != s) return 0;
}
return 1;
}


ll pollard(ll n) {
ll x = 0, y = 0, t = 30, prd = 2, i = 1, q;
auto f = [&](ll x) { return modmul(x, x, n) + i; } ;
while (t++ % 40 || __gcd(prd, n) == 1) {
if (x == y) x = ++i, y = f(x);
if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
x = f(x), y = f(f(y));
}
return __gcd(prd, n);
}
vector<ll> factor(ll n) {
if (n == 1) return { } ;
if (isPrime(n)) return { n } ;
ll x = pollard(n);
auto l = factor(x), r = factor(n / x);
l.insert(l.end(), all(r));
return l;
}

std::tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    if (b == 0)
        return std::make_tuple(a, 1, 0);
    long long gcd, x1, y1;
    std::tie(gcd, x1, y1) = extended_gcd(b, a % b);
    long long x = y1;
    long long y = x1 - (a / b) * y1;
    return std::make_tuple(gcd, x, y);
}


long long mod_inverse(long long a, long long m) {
    long long gcd, x, y;
    std::tie(gcd, x, y) = extended_gcd(a, m);
    if (gcd != 1) {
        // Inverse doesn't exist
        return -1;
    } else {
        // Ensure the inverse is positive
        long long inv = (x % m + m) % m;
        return inv;
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
 
    int t=1;
    cin>>t;

    while (t--)
    {	//Lesgooooooo!!!!
        ll k,n;
        cin>>k>>n;
        cout<<n<<" ";
        forf(i,2,k+1)
        {
            vector<ll> fac = factor(i);
            ll s = fac.size();
            map<ll,ll> cnt;
            for(auto x:fac)
            {
                cnt[x]++;
            }
            s = min(s,n);
            vector<ll> dp(s+1,0);
            dp[0] =0;
            dp[1] =1;

            function<ll(ll)> prod = [&](ll num)->ll{
                ll ret = 1;
                for(auto x:cnt)
                {
                    for(int l = num;l>=1;l--)
                    {
                        (ret*= (x.se+l)%modn)%=modn;
                        (ret*= mod_inverse(l,modn))%=modn;
                    }
                }
                return ret%modn;
            };
            for(int r = 2;r<=s;r++)
            {
    
                (dp[r] += prod(r-1)%modn)%=modn;
                ll rcj = r%modn;
                for(int j = 1;j<=r-1;j++)
                {
                    dp[r] = ((dp[r] - (dp[r-j]*rcj)%modn)%modn +modn)%modn;
                    (rcj*= (r-j)%modn)%=modn;
                    (rcj*=mod_inverse(j+1,modn))%=modn;
                }
                // cout<<i<<" "<<r<<" "<<dp[r]<<" ";
                // cout<<endl;
            }
            ll st = (n+1)%modn;
            ll ans =0 ;
            // cout<<i<<": "<<endl;
            forf(j,1,s+1)
            {
                (st*=(n+1-j)%modn)%=modn;
                (st*=mod_inverse(j+1,modn))%=modn;
        
                (ans+= (st*dp[j])%modn)%=modn;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}

