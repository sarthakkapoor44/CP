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
        ll n,m,k;cin>>n>>m>>k;
        // n trees// m colors //k beauty
        v arr(n);rep(i,n)cin>>arr[i];
        vector<vector<ll> > colors(n,vector<ll>(m,0));
        rep(i,n)rep(j,m)cin>>colors[i][j];
        ll dp[n+1][m+1][k+1];
        rep(i,n+1)rep(j,m+1)rep(l,k+1)dp[i][j][l] =INF;
        dp[0][0][0] =0;
        forf(x,1,n+1)
        {
            if(arr[x-1])
            {
                forf(y,0,m+1)
                {   forf(z,0,k+1)
                    {
                        if(dp[x-1][y][z]!=INF)
                        {
                            if(y==arr[x-1])
                               {
                                dp[x][arr[x-1]][z] = min(dp[x][y][z],dp[x-1][y][z]);
                               }
                            else 
                                {
                              if(z+1<=k)dp[x][arr[x-1]][z+1] = min(dp[x][arr[x-1]][z+1],dp[x-1][y][z]);
                                }
                        }
                    }
                }
            }
            else
            {
                  forf(y,0,m+1)
                {   forf(z,0,k+1)
                    {
                        forf(c,1,m+1){
                            if(dp[x-1][y][z]!=INF)
                            {
                                if(y==c)dp[x][c][z] = min(dp[x][c][z],dp[x-1][y][z]+colors[x-1][c-1]);
                             else if((z+1<=k)) dp[x][c][z+1] = min(dp[x][c][z+1],dp[x-1][y][z]+colors[x-1][c-1]);
                            }
                        }
                    }
                }
            }
        }
        ll val =INF;
        forf(i,1,m+1)val =min(val,dp[n][i][k]);
        if(val==INF)val=-1;
        cout<<val;ce;
    }

    return 0;
}
