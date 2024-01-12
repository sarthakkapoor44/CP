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
ll dp[1000001][100];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        ll n,x;
        cin>>n>>x;
        
        ll arr[n];rep(i,n){cin>>arr[i];}
        // rep(i,1000000){rep(j,100){dp[i][j]=0;}}
        sort(arr,arr+n);
        dp[0][0]=1;
        // rep(i,n){dp[0][i]=1;}
            rep(i,x+1){
            rep(j,n){
            
                if(i+arr[j]<=x){
                    (dp[i+arr[j]][j]+=dp[i][j-1])%=MODN;
                }
                if(i!=0 && j+1<n){
                  (dp[i][j+1]+=dp[i][j])%=MODN;
                }
                
            }
        }
        rep(i,x+1){rep(j,n){cout<<dp[i][j]<<" ";}ce;}
        ll sum= 0;
        rep(i,n){sum+=dp[x][i];}
        cout<<sum;ce;
    }
return 0;
}