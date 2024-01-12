#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
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
    
    
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        v dp(n+1,INT_MAX);
        dp[1]=0;dp[2] = abs(arr[1]-arr[0]);
        forf(i,3,n+1){
                dp[i] = min(dp[i],dp[i-1]+abs(arr[i-1]-arr[i-2]));
                dp[i] = min(dp[i],dp[i-2]+abs(arr[i-1]-arr[i-3]));
        }
    cout<<dp[n];
return 0;
}