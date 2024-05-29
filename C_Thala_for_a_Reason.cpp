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
ll dp[7][111][11];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll x,y;
        cin>>x>>y;
        dp[0][0][y]=1;
        forf(i,0,6)
        {
            rep(r,101)
            {
                forf(w,1,y+1)
                {
                  if(r<x){ dp[i+1][r][w]+= dp[i][r][w];
                    dp[i+1][r+1][w]+= dp[i][r][w];
                    dp[i+1][r+2][w]+= dp[i][r][w];
                    dp[i+1][r+3][w]+= dp[i][r][w];
                    dp[i+1][r+4][w]+= dp[i][r][w];
                    dp[i+1][r+6][w]+= dp[i][r][w];
                    if(w>0)dp[i+1][r][w-1]+= dp[i][r][w];
                   }
                }
            }
        }
       ll sum =0;
    //   cout<< dp[2][2][6];ce;
    forf(k,1,7){ 
       forf(i,x,101)
       {
        forf(j,1,y+1)
        {
            // cout<<dp[k][i][j]<<" ";
            sum+=dp[k][i][j];
        }
        // ce;
       }
 
    }
          cout<<sum;ce;
    }

    return 0;
}
