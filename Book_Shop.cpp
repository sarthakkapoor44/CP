///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
bool is_prime[MAXN];
int spf[MAXN];

// Function declarations
void sieve();
void sieve_of_eratosthenes();
ll gcd(ll a, ll b);
int dp[1001][100001];
int main() {
   
    
        ll n,x;
        cin>>n>>x;
        //Lesgooooooo!!!!
        vector<int> price(n,0),pages(n,0);
        rep(i,n){cin>>price[i];}
        rep(i,n){cin>>pages[i];}
     
        forf(i,1,n+1)
        {
            rep(j,x+1){
                dp[i][j] = max(dp[i-1][j],dp[i][j]);
                if(j-price[i-1]>=0){
                    dp[i][j]= max(dp[i-1][j-price[i-1]]+pages[i-1],dp[i][j]); 
                }
            }
        
        }
        cout<<dp[n][x];ce;

    return 0;
}

