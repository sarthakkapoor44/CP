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
        ll n,l,k;
        scanf("%lld %lld %lld",&n,&l,&k);
        v dist(n),speed(n);
        rep(i,n)cin>>dist[i];
        rep(i,n)cin>>speed[i];
        dist.pb(l);
        speed.pb(0);
        vector<vector<ll> > dp(n+1,vector<ll>(k+1,INF));
        dp[n][0] =0;
        forb(i,n-1,0)
        {
            
            dp[i][0] = min(dp[i][0],dp[i+1][0]+(dist[i+1]-dist[i])*speed[i]);
            forf(j,i+1,n+1)
            {   
                forf(t,1,k+1)
                if((t-(j-i-1))>=0)dp[i][t] = min(dp[i][t],(dist[j]-dist[i])*speed[i]+dp[j][t-(j-i-1)]);
            }
        }
        ll val=INF;
        rep(i,k+1)val = min(val,dp[0][i]);
        cout<<val;ce;
        // rep(i,n+1){rep(j,k+1)cout<<dp[i][j]<<" ";ce;}    
    }

    return 0;
}
