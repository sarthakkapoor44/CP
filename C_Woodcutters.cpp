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
        vp pos(n+2,mp(0,0));
        forf(i,1,n+1){
            cin>>pos[i].fi>>pos[i].se;
        }
       vector<vector<ll> >dp(n+1,vector<ll>(3,0));
       pos[0].fi = -INF;
       pos[n+1].fi = INF;
       forf(i,1,n+1){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if(pos[i].fi-pos[i-1].fi>pos[i].se){
            dp[i][1]= max(dp[i-1][1],dp[i-1][0])+1;
            if(pos[i-1].se+pos[i].se<pos[i].fi-pos[i-1].fi){
              dp[i][1]= max(dp[i][1],dp[i-1][2]+1);  
            }
        }
        if(pos[i+1].fi-pos[i].fi>pos[i].se){
            dp[i][2]= max(dp[i-1][1],max(dp[i-1][0],dp[i-1][2]))+1;
        }
       }
    //    forf(i,1,n+1){cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2];ce;}
       cout<<max(dp[n][2],max(dp[n][1],dp[n][0]));
    }

    return 0;
}


// 3 4
// 1 2 3 4 5 6 7
// . . . - - - -