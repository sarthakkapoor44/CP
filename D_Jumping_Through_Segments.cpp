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
int check(ll mid, vp range,ll n){
ll l=0,r=0;
ll cq=1;
// ll count=0;
rep(i,n)
{
   l = max(l-mid,range[i].fi);
   r = min(r+mid,range[i].se);
   if(l>r){cq=0;break;}
}
return cq;
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
        vp range;
        rep(i,n){ll a,b;cin>>a>>b;range.pb(mp(a,b));}
        ll left =0,right =1e9;
        ll mid=(left+right)/2; ; ll ans =right;
        while(left<=right){
            mid = (left+right)/2;
            if(check(mid,range,n)){if(mid<=ans){ans =mid;} right = mid-1;}
            else{left =mid+1;}
            //   cout<<left<<" "<<mid<<" "<<right;ce;
        }
        cout<<ans;ce;
        // cout<<check(7,range,n);
    }
return 0;
}