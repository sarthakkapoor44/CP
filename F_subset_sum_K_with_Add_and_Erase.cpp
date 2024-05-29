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
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
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
ll dp[50001];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    {   //Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
    
        dp[0]=1;
        rep(i,n){
            char sign;ll num;cin>>sign>>num;
            if(sign=='+')
            {   
               
                forb(j,k,0)
                {
                    if(num+j<=k)(dp[num+j]+=dp[j]%modn)%=modn;
                }
                cout<<dp[k];ce;
            }
            else
            {
                 rep(j,k+1)
                {   
                   
                    if(dp[j] && j-num>=0 && dp[j-num])(dp[j]-=dp[j-num])%=modn;
                     (dp[j]+=modn)%=modn;
                   
                }
                cout<<dp[k];ce;
            }
      
        
        }
        
    }

    return 0;
}
