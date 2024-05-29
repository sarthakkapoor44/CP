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

int dp[501][501][501];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        int n,x;
        cin>>n>>x;
        int arr[n];
        rep(i,n)cin>>arr[i];
        
        rep(i,n)rep(j,501)rep(k,501)dp[i][j][k]=INT_MAX;
        dp[0][arr[0]][x]=0;
        if(arr[0]>x)dp[0][x][arr[0]]=1;
        // dp[i][last][x]
        forf(i,1,n)
        {
            rep(j,501)
            {
                rep(k,501)
                {
                 if(arr[i]>=j) dp[i][arr[i]][k] = min(dp[i-1][j][k],dp[i][arr[i]][k]);
                 if(arr[i]>k && k>=j && dp[i-1][j][k]!=INT_MAX)dp[i][k][arr[i]] = min(dp[i][k][arr[i]],dp[i-1][j][k]+1);
                }
            }
        } 
        int ans =INT_MAX;
        rep(i,501){rep(j,501)ans= min(ans,dp[n-1][i][j]);}
       
        if(ans==INT_MAX)cout<<-1;
        else cout<<ans;
        ce;
    }

    return 0;
}

// a1 a2 a3 a4 a5 
// x will go on to increase
// x<= 500 , ai<= 500 , n<=500
// (500)^3 algorithm possible
// dp[i][last][x] 
// i-1 sorted 
