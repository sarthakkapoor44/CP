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
        ll n,k;
        cin>>n>>k;
        vp v1,v2;
        rep(i,n){ll a ;cin>>a;v1.pb(mp(a,i));}
        rep(i,n){ll a ;cin>>a;v2.pb(mp(a,i));}
        srt(v2);srt(v1);
        // rep(i,n){cout<<v1[i].fi<<" ";}ce;
        // rep(i,n){cout<<v2[i].fi<<" ";}ce;
        ll arr[n];
        rep(i,n-k){arr[i]= v2[i+k].fi;}
        forf(i,n-k,n){arr[i] = v2[i-n+k].fi;}
        ll count=0;
        ll arr_c[n];
        rep(i,n){if(v1[i].fi>arr[i]){count++;}arr_c[v1[i].se]=arr[i];}
        if(count==k){pyes;ce;rep(i,n){cout<<arr_c[i]<<" ";}ce;}
        else{pno;ce;}
    }
return 0;
}