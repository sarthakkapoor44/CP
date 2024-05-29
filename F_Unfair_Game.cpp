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
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
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

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
int dp[201][201][201];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
     rep(i,200+1)
        {
            rep(j,200+1)
            {
                rep(k,200+1)
                {
                    dp[i][j][k]=0;
                    if(i || j || k)
                    { 
                        int cq=0;
                        if(i%2 == j%2 && j%2== k%2){cq=1;}
                        if(i>0)dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+cq);
                        if(j>0)dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]+cq);
                        if(k>0)dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]+cq);
                        
                    }
                }
            }
        } 

    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
       
        cout<<dp[a][b][c]+(d)/2;ce;
    }
 
       return 0;  
    }

   
