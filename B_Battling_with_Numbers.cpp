#include<bits/stdc++.h>
#include<iterator>
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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n,m;
        cin>>n;
        vp vect1,vect2;
        unordered_map<ll,ll> map1,map2;
        rep(i,n){ll num;cin>>num;vect1.pb(mp(num,0));}
        rep(i,n){ll num;cin>>num;vect1[i].se = num;}
        rep(i,n){map1[vect1[i].fi]=vect1[i].se;}
        cin>>m;
        rep(i,m){ll num;cin>>num;vect2.pb(mp(num,0));}
        rep(i,m){ll num;cin>>num;vect2[i].se = num;}
        rep(i,m){map2[vect2[i].fi]=vect2[i].se;}
        ll ans =1;
        unordered_map<ll,ll>::iterator itr;
       
        for(itr = map2.begin();itr!=map2.end();itr++)
{
    ll val1 = itr->fi;ll val2 =itr->se;
    if(map1[val1]-val2<0){ans =0;break;}
    map1[val1]= map1[val1] - val2;
         
}
ll val = 998244353;
if(ans){
        for(itr = map1.begin();itr!=map1.end();itr++)
{
  if(itr->se>0){ans*=2;ans= ans%val;}
         
}
}
      cout<<ans%val;ce;
    }
return 0;
}