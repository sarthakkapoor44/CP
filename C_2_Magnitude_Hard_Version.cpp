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
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<ll> arr(n);
        rep(i,n)cin>>arr[i];
        vector<vector<ll>> dp(n,vector<ll>(2)),dp2(n,vector<ll>(2,0));

        rep(i,n)
        {
            dp[i][0]=INF;
            dp[i][1]=-INF;
        } 

        dp[0][0] = arr[0];
        dp[0][1] = abs(arr[0]);

      
        if(arr[0]>=0){dp2[0][1]=2;}
        else {  dp2[0][1]=1;
        dp2[0][0]=1;}
        forf(i,1,n)
        {
            dp[i][0] = min(dp[i-1][0]+arr[i],dp[i-1][1]+arr[i]);
            dp[i][1] = max(abs(dp[i-1][0]+arr[i]),abs(dp[i-1][1]+arr[i]));
            
            if(dp[i][1]!=dp[i][0])
            {
            if(dp[i-1][0]+arr[i]==dp[i][0])(dp2[i][0]+=dp2[i-1][0]%modn)%=modn;
            if(abs(dp[i-1][0]+arr[i])==dp[i][0])(dp2[i][0]+=dp2[i-1][0]%modn)%=modn;
            if(dp[i-1][1]+arr[i]==dp[i][0])(dp2[i][0]+=dp2[i-1][1]%modn)%=modn;
            if(abs(dp[i-1][1]+arr[i])==dp[i][0])(dp2[i][0]+=dp2[i-1][1]%modn)%=modn;
            }

            if(dp[i-1][0]+arr[i]==dp[i][1])(dp2[i][1]+=dp2[i-1][0])%=modn;
            if(abs(dp[i-1][0]+arr[i])==dp[i][1])(dp2[i][1]+=dp2[i-1][0])%=modn;
            if(dp[i-1][1]+arr[i]==dp[i][1])(dp2[i][1]+=dp2[i-1][1]%modn)%=modn;
            if(abs(dp[i-1][1]+arr[i])==dp[i][1])(dp2[i][1]+=dp2[i-1][1]%modn)%=modn;
            

        }
        // rep(i,n){cout<<dp2[i][0]<<" "<<dp2[i][1];ce;}
        cout<<dp2[n-1][1]%modn;ce;
    }

    return 0;
}
