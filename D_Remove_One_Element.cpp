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
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n+1];
        forf(i,1,n)cin>>arr[i];
        ll  dp[n+1][2];
        rep(i,n+1){dp[i][0]=1;dp[i][1]=1;}
        
        dp[0][0]=0;dp[0][1]=0;
        forf(i,0,n+1){
        
        if(i+1<=n && arr[i+1]>arr[i]){
            dp[i+1][0]+= dp[i][0];
            dp[i+1][1]+= dp[i][1];
    }
        else{
            if(i+2<=n && arr[i+2]>arr[i]){dp[i+2][1] = max(dp[i+2][1],dp[i][0]+1);}
            }   
        cout<<i<<" "<<dp[n][0]<<" "<<dp[n][1];ce;
        }
        // forf(i,1,n+1){cout<<dp[i][0]<<" "<<dp[i][1];ce;}
         cout<<max(dp[n][1],dp[n][0]);ce;
    }
return 0;
}