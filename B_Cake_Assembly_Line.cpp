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
        ll n,w,h;
        cin>>n>>w>>h;
        ll nozzle[n],cake[n];
        vp range;
        rep(i,n){cin>>cake[i];}rep(i,n){cin>>nozzle[i];}
        rep(i,n){ll upper = cake[i]+w-h-nozzle[i];ll lower= cake[i]-w -(nozzle[i]-h);range.pb(mp(lower,upper));}
        // rep(i,n){cout<<range[i].fi<<"<->"<<range[i].se<<" ";}ce;
        ll ans=0;
        ll left,right;
        rep(i,n){
            ll low =range[i].fi;ll up = range[i].se;
            if(low>up){swap(low,up);}
            if(i==0){left =low;right=up;}
            else{if(low>left){left =low;}
            if(up<right){right=up;}
            }
        }
        // cout<<left<<" "<<right;ce;
        if(left<=right){ans=1;}
        if(ans){pyes;}else{pno;}ce;
    }
return 0;
}