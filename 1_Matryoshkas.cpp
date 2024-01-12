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
        ll sets =0;
        sort(arr,arr+n);
        vp vect;
        vect.pb(mp(arr[0]-1,0));
        ll i=0;
        while(i<n){
            ll count=1;
        while(arr[i+1]==arr[i]){i++;count++;}
        vect.pb(mp(arr[i],count));i++;
        if(n>1){if(i>=1 && arr[i]-arr[i-1]>=2){vect.pb(mp(arr[i-1]+1,0));}}
        }
        ll sz =vect.size();
        // rep(i,sz){cout<<vect[i].fi<<"->"<<vect[i].se<<" ";}
        rep(i,vect.size()-1){
            if(vect[i+1].se-vect[i].se>=0){sets+=vect[i+1].se-vect[i].se;}
        }
        cout<<sets;ce;
    }
return 0;
}

// ll diff = vect[sz-1].se-vect[sz-2].se;
//         vect.pb(mp(vect[sz-1].fi+2,diff));
//         rep(i,vect.size()){cout<<vect[i].fi<<"->"<<vect[i].se<<" ";}ce;
//         rep(i,vect.size()-1){if(vect[i+1].fi-vect[i].fi>1){sets+=vect[i].se;}}
//         cout<<sets;
//         rep(i,vect.size()-1){
//         if(i==0 && vect.size()>2){if(vect[i+2].fi-vect[i+1].fi>1){sets-=vect[i+1].se;}}
//                 if(vect[i+1].se-vect[i].se>=0 and vect[i+1].fi-vect[i].fi==1){sets+=vect[i+1].se-vect[i].se;}
            
//         }
//         if(vect.size()>3){if(vect[sz-2].fi-vect[sz-3].fi==1)sets-=vect[sz-2].se-vect[sz-3].se;}
//         cout<<sets;ce;