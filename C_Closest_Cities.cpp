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
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        v arr(n+1,-INT_MAX);
        forf(i,1,n+1){cin>>arr[i];}
        v dp(n+1,INT_MAX);
        dp[1]=0;
        forf(i,1,n){
            ll prev = arr[i]-arr[i-1];
            ll next=INT_MAX;
            next=arr[i+1]-arr[i];
            if(next<prev)
            {
            dp[i+1]=min(dp[i+1],dp[i]+1);
            dp[i-1] =min(dp[i-1],dp[i]+(arr[i]-arr[i-1]));
            }
            else{
                dp[i+1]=min(dp[i+1],dp[i]+arr[i+1]-arr[i]);
                dp[i-1] =min(dp[i-1],dp[i]+1);
            }
          
        }

        v dp1(n+1,INT_MAX);
        forf(i,1,n+1){arr[i]=-arr[i];}
      
        srt(arr);
        // rep(i,n+1){cout<<arr[i]<<" ";}ce;
        dp1[1]=0;
        forf(i,1,n){
            ll prev = arr[i]-arr[i-1];
            ll next=INT_MAX;
            next=arr[i+1]-arr[i];
            if(next<prev)
            {
            dp1[i+1]=min(dp1[i+1],dp1[i]+1);
            dp1[i-1] =min(dp1[i-1],dp1[i]+(arr[i]-arr[i-1]));
            }
            else{
                dp1[i+1]=min(dp1[i+1],dp1[i]+arr[i+1]-arr[i]);
                dp1[i-1] =min(dp1[i-1],dp1[i]+1);
            }
          
        }
        
        // forf(i,0,n){cout<<dp1[i+1]<<" ";}ce;
        
        ll m;cin>>m;
        rep(i,m){
            ll a,b;cin>>a>>b;
             if(b>a){cout<<dp[b]-dp[a];}
            else{cout<<-(dp1[n-a+1]-dp1[n-b+1]);}
        ce;
        }
    }

    return 0;
}
/*  else{
                dp[i] = dp[i-1]+arr[i]-arr[i-1];
                if(i+1<=n){dp[i] = min(dp[i],dp[i+1]+1);}
            }*/


//-----Smallest prime factor----------//
/*
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