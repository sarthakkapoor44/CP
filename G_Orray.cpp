#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end()
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
const ll MODN= 1e9 + 7;
const ll MAXN=1000001;
int spf[MAXN];
void sieve();
ll gcd(ll a, ll b);
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        v vect(n,0);rep(i,n)cin>>vect[i];
        auto val  = max_element(all(vect));
        ll index = val- vect.begin();
        v check(n,0);
        v ans;ans.pb(vect[index]);check[index]=1;
        ll cur  = vect[index];
        rep(j,31)
        {
            ll max_ = INT_MIN;
            ll idx = 0;
        rep(i,n)
                {
                    if(check[i]!=1){
                        if((cur|vect[i])>max_)
                        {
                        max_ = cur|vect[i];
                        idx = i;
                        }
                        }
                }
            cur  = cur|vect[idx];
            ans.pb(vect[idx]);
            check[idx]=1;
        }
        rep(i,n){if(check[i]!=1){ans.pb(vect[i]);}}
        rep(i,n){cout<<ans[i]<<" ";}ce;
    }
return 0;
}

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}
