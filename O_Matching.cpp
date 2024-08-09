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
        vector<vector<ll> >grid(n,vector<ll>(n));
        rep(i,n)rep(j,n)cin>>grid[i][j];
        vector<ll>dp(1<<n,0);
        rep(i,n)
        {
            if(grid[0][i])dp[1<<i]=1;
        }
        for(int s = 1;s<(1<<n);s++)
        {
            ll idx = __builtin_popcount(s);
            for(int i=0;i<n;i++)
            {
                if((s&(1<<i)) && grid[idx-1][i])
                {
                    (dp[s]+= dp[s^(1<<i)]%MODN)%=MODN;
                } 
            }
        }
        cout<<dp[(1<<n)-1];ce;
    }



    return 0;
}
