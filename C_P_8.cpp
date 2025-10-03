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
 
const int LIM = 1e6;
bitset<LIM> isPrime;
vll eratosthenes() {
const int S = (int)round(sqrt(LIM)), R = LIM / 2;
vll pr = { 2 } , sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
vector<pair<ll,ll>> cp;
for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
cp.push_back( { i, i * i / 2 } );
for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
}
for (int L = 1; L <= R; L += S) {
array<bool, S> block { } ;
for (auto &[p, idx] : cp)
for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
forf(i,0,min(S, R - L))
if (!block[i]) pr.push_back((L + i) * 2 + 1);
}
    for(int i:pr)isPrime[i]=1;
    return pr;
}
int isPalindrome(ll n)
{
    ll rev = 0;
    ll temp = n;
    while (temp != 0)
    {
        rev = rev * 10 + temp % 10;
        temp = temp / 10;
    }
    return n == rev;
}
ll convert_to_base_8(ll n)
{
    ll ans = 0;
    ll i = 1;
    while (n > 0) {
        ans += (n % 8) * i;
        n /= 8;
        i *= 10;
    }
    return ans;
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    eratosthenes();
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vll arr;
        ll cnt =0 ;
        rep(i,LIM)
        {
            if(cnt>=n)break;
            if(isPrime[i])
            {
                arr.pb(convert_to_base_8(i));
                cnt++;
            }
        }
        out(arr);
        
    }

    return 0;
}
