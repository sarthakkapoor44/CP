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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);    
    string s, t;
    cin >> s >> t;
    ll n = s.length(), m = t.length();
    vector<vector<ll> > dp(n+1, vector<ll>(m+1,INF));
    dp[0][0]=0;
    rep(i,n){dp[i][0]=i;}
    rep(i,m)dp[0][i]=i;
    for(ll i = 0; i <n; ++i) {
        for(ll j = 0; j <m; ++j) {
            if(s[i] == t[j]) {dp[i+1][j+1] =min(dp[i][j],dp[i+1][j+1]);
            }
            else { 
              if(i+1<=n && j+1<=m){ dp[i+1][j+1]=min(dp[i+1][j],dp[i][j+1])+1;
              dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+1);
              }
                }
           
    }
    }

    cout << dp[n][m]<< '\n';
    // rep(i,n+1){
    //     rep(j,m+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     ce;
    // }
    return 0;

}
