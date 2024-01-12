#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        sort(arr,arr+n,greater<ll>());
        v ans;
        ans.pb(arr[0]);
       ll i =0;
       ll count =0;
       ll curr_gcd = arr[0];
       ll unused[n];
       ll curr = arr[0];
       memset(unused,1,sizeof(unused));
       unused[0] =0;
       curr_gcd =arr[0];
       ll index =0;
    //    ll cum_gcd  = INT_MIN;
       while(count<n-1){
        ll gcd_val =INT_MIN;
        rep(i,n){
            ll value=-1;
            if(i!=index && unused[i]){
                value = gcd(curr_gcd,arr[i]);
                if(value>gcd_val){gcd_val =value;index= i;}
            }
            }
        ans.pb(arr[index]);
        curr  =arr[index];
        curr_gcd = gcd_val;
        unused[index] =0;
        count++;
       }
        
        rep(i,ans.size()){cout<<ans[i]<<" ";}ce;
    }
return 0;
}   