///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
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
    // Optimize input/output (remove if only using cin cout)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
   
    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        v arr(n+1,0);
          v indices(n+1,0);
        forf(i,1,n+1){cin>>arr[i];indices[arr[i]]=i;}
        unordered_map<ll,vector<ll> > adj;
        ll val;
        v dp(n+1,1);
      
        forf(i,1,n+1){
            val =arr[i];
            for(int j= i- (n/arr[i])*val;j<=i+(n/arr[i])*val;j+=val){
                if(j>n){break;}
                if(j>0){
                    if(arr[j]>val){
                        adj[i].pb(j);
                    }
                }
            }
             if(adj[i].size()==0){dp[i]=0;}
        }
        forb(i,n,1){
             dp[indices[i]]=0;
           
            // cout<<indices[i]<<" ";
                for(auto j:adj[indices[i]]){
                // cout<<j<<" ";
                if(dp[j]==0){dp[indices[i]]=1;break;}
            }
          ce;
        }

        // forf(i,1,n+1){
        //     cout<<i<<"->";
        //     rep(j,adj[i].size()){
        //        cout<<adj[i][j]<<" ";
        //     }
        //     ce;
        // }
        forf(i,1,n+1){if(dp[i]){cout<<'A';}else cout<<'B';}ce;
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