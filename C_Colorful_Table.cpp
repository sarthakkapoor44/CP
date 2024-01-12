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
#define all(a) a.begin(),a.end()
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
        vp vect;
        rep(i,n){ll a;cin>>a;vect.pb(mp(a,i));}
        sort(all(vect));       
        ll mx_index[n];
        ll max_index = INT_MIN;
        ll min_indices[n];
        ll min_index = INT_MAX;
        forb(i,n-1,0){

            max_index= max(max_index,vect[i].se);mx_index[vect[i].se] =max_index;
          }
        forb(i,n-1,0){
            min_index= min(min_index,vect[i].se);min_indices[vect[i].se] =min_index;
          }
        ll ans[k+1];
        memset(ans,0,sizeof(ans));
        rep(i,n-1){if(vect[i+1].fi==vect[i].fi){min_indices[vect[i+1].se] =min_indices[vect[i].se];}}
        rep(i,n){
            ans[vect[i].fi] = 2*(mx_index[vect[i].se] - min_indices[vect[i].se]+1);
        }
        forf(i,1,k+1){cout<<ans[i]<<" ";}ce;
        
    }
return 0;
}