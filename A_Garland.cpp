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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll one=(n+1)/2,zero=(n)/2;
        v arr(n);rep(i,n){cin>>arr[i];if(arr[i]){if((arr[i]%2))one--;else{zero--;}}}
        ll dp[n][one+1][zero+1][2];
        rep(i,n){rep(j,one+1){rep(k,zero+1){dp[i][j][k][1]=INF;dp[i][j][k][0]=INF;}}}
        if(arr[0]){
            dp[0][one][zero][(arr[0]%2)]=0;
        }
        else{
              dp[0][one-1][zero][1]=0;
             dp[0][one][zero-1][0]=0;
        }
        forf(i,1,n)
        {
          rep(j,one+1)
          {
            rep(k,zero+1)
            {
                if(arr[i])
                {
                    dp[i][j][k][(arr[i]%2)] = min(dp[i-1][j][k][arr[i]%2], min((long long)INF,dp[i-1][j][k][1-(arr[i]%2)]+1));
                }
                else
                {
                 if(j-1>=0)   dp[i][j-1][k][1] =  min(dp[i-1][j][k][1], min((long long)INF,dp[i-1][j][k][0]+1));
                  if(k-1>=0)  dp[i][j][k-1][0] =  min(dp[i-1][j][k][0], min((long long)INF,dp[i-1][j][k][1]+1));
                }
            }
          }
        }
        // cout<<dp[2][0][0][0];ce;
        ll ans  =INF;
        rep(i,one+1){
            rep(j,zero+1)
            {
                ans = min(ans,dp[n-1][i][j][0]);
                ans = min(ans,dp[n-1][i][j][1]);
            }
        }
        
        cout<<ans;ce;
    }

    return 0;
}
