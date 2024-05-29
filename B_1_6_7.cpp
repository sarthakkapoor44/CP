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
        ll a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        if(c-b>1){cout<<0;}
        else
        {
            vector<vector<ll> >  dp(b+1,vector<ll>(2,0));
            dp[0][0] = 1;
            dp[0][1] = 0;
            forf(i,1,a)
            {
                (dp[i][0] = ((dp[i-1][0]*55)%modn +  (dp[i-1][1]*45)%modn)%modn)%=modn;
                (dp[i][1] = ((dp[i-1][0]*45)%modn + (dp[i-1][1]*55)%modn)%modn)%=modn;
            }
           
            if(a!=b)
            {
                (dp[a][1] = ((dp[a-1][0]*45)%modn +  (dp[a-1][1]*54)%modn)%modn)%=modn;
                (dp[a][0] = ((dp[a-1][0]*45)%modn +  (dp[a-1][1]*36)%modn)%modn)%=modn;
            }
            else if (a==b)
            {
                (dp[a][1] = ((dp[a-1][0]*45)%modn +  (dp[a-1][1]*53)%modn)%modn)%=modn;
                (dp[a][0] = ((dp[a-1][0]*36)%modn +  (dp[a-1][1]*28)%modn)%modn)%=modn;
            }
           
            forf(i,a+1,b)
            {
                (dp[i][0] = ((9*dp[i-1][1])%modn + (10*dp[i-1][0])%modn)%modn)%=modn;
                (dp[i][1] = (dp[i-1][1])%modn)%=modn;
            }
            if(a!=b)
            {
                (dp[b][0] = ((8*dp[b-1][1])%modn + (9*dp[b-1][0])%modn)%modn)%=modn;
                (dp[b][1] = (dp[b-1][1])%modn)%=modn;
            }
            
            //  cout<<dp[1][0]<<" "<<dp[ 1][1]<<" "<<dp[2][0]<<" "<<dp[2][0]<<endl;
            if(c>b)cout<<dp[b][1];
            else cout<<dp[b][0];;
        }
        ce;
    }

    return 0;
}

// 1
//  