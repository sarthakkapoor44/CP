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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);

    {   //Lesgooooooo!!!!
        ll h,w,n;
        scanf("%lld %lld %lld",&h,&w,&n);
        vector<vector<char> > grid(h,vector<char>(w,'.'));
        ll i=0,j=0,dir=0;
        while(n--){
            if(grid[i][j]=='.'){grid[i][j]='#';(dir+=1)%=4;}
            else{dir-=1;if(dir<0){dir+=4;}dir%=4;grid[i][j]='.';}
            if(dir==0){
                i = (i-1);
                if(i<0){i+=h;}
                i%=h;
            }
            else if(dir==1){
                j++;
                j%=w;
            }
            else if(dir==2){
                i++;
                i%=h;
            }
            else if(dir==3){
                j--;
                if(j<0){j+=w;}
                j%=w;
            }
        }
        rep(i,h){
            rep(j,w){
                cout<<grid[i][j];
            }
            ce;
        }
        
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
/*
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
*/

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