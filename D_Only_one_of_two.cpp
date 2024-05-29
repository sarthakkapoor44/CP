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
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
ll gcd(ll a, ll b);

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    // int t=1;
    // scanf("%d",&t);
    // while (t--)
    {   //Lesgooooooo!!!!
        ll n,m,k;
        scanf("%ulld %lld %lld",&n,&m,&k);
        ll gcd_ = gcd(n,m);
        ll val  = (n+m)/gcd_ - 2;
        ll num  =  ceil(k/(val*1.0));
        ll left = k - (num-1)*val;
        ll start  = ((n*m)/gcd_)*(num-1);
        ll ratio = max(n,m)/min(n,m);
        ll groups = left/(ratio+1);
        left-= max(groups-1,0ll)*(ratio+1);
        start = start+ max((groups-1),0ll)*max(n,m);
        if(!(left%(ratio+1))){cout(max(n,m)+start);}
        else {
            ll ans = start +left*(min(n,m));
            cout(start+ left*(min(a,b)));
        }
        cout(start);
        cout(left);
    }

    return 0;
}

//-----Smallest prime factor----------//
/*
void sieve() {
for (int i = 1; i < MAXN; i++)
    spf[i] = i;
 for (int i = 2; i <  MAXN; i++) {
if (spf[i] != i)
    continue;
for (int d = 2 * i; d < MAXN; d += i)
spf[d] = min(spf[d], i);
}
}
*/


//-----GCD----------//

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


//-----Sieve of eratosthenes----------//
/*
void sieve_of_eratosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i <= MAXN; i++) {
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (ll j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
*/