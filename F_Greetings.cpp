#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;

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
        vp vect;
        rep(i,n){ll a,b;cin>>a>>b;vect.pb(mp(a,b));}
        srt(vect);
        v ms;
        rep(i,n){ms.pb(vect[i].se);}
        srt(ms);
        // rep(i,n){ms.insert(vect[i].se);}
        ll ans=0;
        ll erased=0;
        rep(i,n){
            v::iterator itr1,itr2;
            itr1 = lower_bound(all(ms),vect[i].se);
            itr2 = upper_bound(all(ms),vect[i].fi);
           
        }
        cout<<ans;ce;
    }
return 0;
}
