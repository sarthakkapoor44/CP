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
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        ll arr[n];
        rep(i,n)cin(arr[i]);
        v diff;
        if(n==1){cout<<1;}
        else
        {
        rep(i,n-1){diff.pb(abs(arr[i+1]-arr[i]));}
        ll k = ceil(log2(n));
        int st[k+1][n];
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
            st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        rep(j,diff.size())
            {
                
                long long sum = 0;
                for (int i = k; i >= 0; i--) 
                {
                    if ((1 << i) <= r - l + 1)
                    {
                    sum += st[i][l];
                    l += 1 << i;
                    }
                }
            }
        }
        ce;
    }

    return 0;
}
