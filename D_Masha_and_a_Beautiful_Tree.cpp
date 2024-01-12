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
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        ll ans =0;
        ll p=1;
        while(pow(2,p)<=n){
            ll val =pow(2,p);
            //  cout<<val;ce;
    for(ll i =0;i<n;i+=val){
            // cout<<i<<"->"<<i+val-1<<" ";
    //  forf(j,i,i+val-1){cout<<arr[j+1]-arr[j]<<" ";}ce;
    //
    // rep(i,n){cout<<arr[i]<<" ";}ce;
    
     forf(j,i,i+val-1){if(j+1<n && arr[j+1]-arr[j]<0){sort(arr+i,arr+val+i);ans++;break;}}
      forf(j,i,i+val-1){if(abs(arr[j+1]-arr[j])!=1){ans=-1;break;}}
      if(ans==-1){break;}
        }
    if(ans==-1){break;}
        p++;
        }
        
        // rep(i,n){cout<<arr[i]<<" ";}ce;
        
        rep(i,n){if(arr[i]!=i+1){ans=-1;break;}}
        cout<<ans;ce;
        
    }
return 0;
}