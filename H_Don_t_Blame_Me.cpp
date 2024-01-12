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
    ll t;cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        ll dp[64][n+1];
        rep(i,64){rep(j,n+1){dp[i][j]=0;}}
        dp[63][0] =1;
        forf(i,1,n+1){
            forb(j,63,0){
            
            (dp[j&arr[i-1]][i] += dp[j][i-1])%=MODN;
            (dp[j][i]+= dp[j][i-1])%=MODN; 
                
            }
        }
        ll sum =0;
        rep(i,64){
            ll val = dp[i][n];
            ll num = __builtin_popcount(i);
            if(num==k){(sum+=val)%=MODN;}
        }
        if(k==6){sum--;}
        cout<<sum;ce;
    }
return 0;
}