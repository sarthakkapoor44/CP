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
        ll n;
        cin>>n;
        ll arr[n];rep(i,n){cin>>arr[i];}
        ll even=0,odd=0;
        v sum;
        rep(i,n){if((i+1)%2==0){even+=arr[i];sum.pb(even);}else{odd+=arr[i];sum.pb(odd);}}
        set<ll> diff;
        ll ans=0;
        ll last_odd=sum[0];
        ll last_even;
        diff.insert(0);
        diff.insert(-sum[0]);
        // rep(i,n){cout<<sum[i]<<" ";}ce;
        if(n!=1){
        forf(i,1,n){
          if((i+1)%2==0){
            if(diff.count(sum[i]-last_odd)==1){ans=1;break;}
            diff.insert(sum[i]-last_odd);last_even=sum[i];
            }  
          else{
            if(diff.count(last_even-sum[i])==1){ans=1;break;}
            diff.insert(last_even-sum[i]);last_odd=sum[i];
            }
        }}
        if(ans){pyes;}else{pno;}ce;

    }
return 0;
}