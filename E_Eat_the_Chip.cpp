///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
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
#define vp vector<pair<ll, ll>>
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
bool is_prime[MAXN];
int spf[MAXN];

// Function declarations
void sieve();
void sieve_of_eratosthenes();
ll gcd(ll a, ll b);
int main() {
    // Optimize input/output
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    int t=1;
    scanf("%d",&t);
    while (t--)
    {
        ll h,w,xa,ya,xb,yb;cin>>h>>w>>xa>>ya>>xb>>yb;
        string ans;
        if(xa>=xb){ans="Draw";}
        else {
        ll diff = abs(xa-xb)-1;
        if(diff%2==0){
            ll alice = (diff/2),bob= diff/2;
            if(abs(ya-yb)<=1){ans="Alice";}
            else{
                if(yb>ya){
                    
                    if(yb+bob-(yb-ya-2)<=w){ans="Draw";}
                    else{ans="Alice";}
                }
                else{
              
                 if(yb-bob+(ya-yb-2)>=1){ans="Draw";}
                 else{ans="Alice";}
                }
            }
        }
        else{
            ll alice =(diff+1)/2,bob = diff/2;
            if(ya==yb){ans ="Bob";}
            else if(abs(ya-yb)>=1){
                if(ya<yb){
                    if(ya-(alice)+(yb-ya-1)>=1){ans="Draw";}
                    else{ans="Bob";}
                }
                else{
                
                    if(ya+alice-(ya-yb-1)<=w){ans="Draw";}
                    else{ans="Bob";}
                }
            }
            }
        }
        cout<<ans;ce;
    }
    return 0;
}

void sieve() {
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        spf[i] = i;

    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

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
