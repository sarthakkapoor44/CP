#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end()
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
const ll MODN= 1e9 + 7;
/*ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}*/
int dp[1000][1000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
        vector<string> grid(n,"");
        rep(i,n){cin>>grid[i];}
       
        rep(i,n){rep(j,n){dp[i][j]=0;}}
        if(grid[0][0]!='*')dp[0][0]=1;
        rep(i,n){rep(j,n){
            if(grid[i][j]!='*'){
              if(i-1>=0){dp[i][j] +=dp[i-1][j]%MODN;}
              dp[i][j]= dp[i][j]%MODN;
              if(j-1>=0){dp[i][j]+=dp[i][j-1]%MODN;}
                   dp[i][j]= dp[i][j]%MODN;
            }
        }}

        cout<<dp[n-1][n-1]%MODN;

    }
return 0;
}