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
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        rep(i,n)cin>>arr[i];
        ll dp[x+1];
        sort(arr,arr+n);
        // here dp[i] represents the number of ways to form the sum=i
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        rep(i,x+1){
            for (auto x:arr){
                if(i-x>=0){
                   dp[i]+=dp[i-x]%MODN;
                    dp[i] = dp[i]%MODN;
                }
                else{break;}
            }
        }
        // rep(i,x+1)cout<<dp[i]<<" ";
        cout<<dp[x]%MODN;
        ce;
        
    }
return 0;
}