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
        ll n,m;
        cin>>n>>m;
        int grid[n][m];
        rep(i,n)rep(j,m)cin>>grid[i][j];
        ll dp[n][m][n][m];
        rep(i,n)rep(j,m)rep(k,n)rep(l,m)dp[i][j][k][l]=INF;
        rep(i,n-1)rep(j,m-1)dp[i][j][i][j]=0;
        rep(i,n)
        {
            rep(j,m)
            {
                
              forf(k,i,n)
              {
                forf(l,j,m)
                {
                    ll sum =0;
                    forf(p,)
                    dp[i][j][k][l] = min(dp[i][j][k][l],)
                }
              }
            }
        }
    }

    return 0;
}
