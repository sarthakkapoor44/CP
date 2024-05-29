///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
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
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);

ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}

vp primeFact(ll num)
{   
    vp temp;
    ll cnt =0;
    if(num==1){return temp;}

    while(!(num%2)){num/=2;cnt++;}
    if((cnt)){temp.pb(mp(2,(cnt)));}

    for(ll i=3;i*i<=num;i++)
    {
        cnt =0;
        while(!(num%i))
        {
            num/=i;cnt++;
        }
        if((cnt))temp.pb(mp(i,(cnt)));
    }
    if(num>1){if(1)temp.pb(mp(num,(1)));}
    return temp;
}

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll a,m;
        cin>>a>>m;
        ll d =  gcd(a,m);
        ll num = (m)/d;
        vp primes = primeFact(num);
        ll ans =1;
        for(auto x:primes)
        {
            ll val = pow(x.fi,x.se);

            ans*=(val-val/x.fi);
        }
        cout<<ans;ce;
    }

    return 0;
}
