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
        
        ll m1,m2,k1,k2,q1,q2;
        cin>>m1>>m2>>k1>>k2>>q1>>q2;
        set<pair<ll,ll> > ump;
        for(int i=-m1;i<=m1;i+=2*m1){
            for(int j= -m2;j<=m2;j+=2*m2){
              
                ump.insert(mp(k1+i,k2+j));
                ump.insert(mp(k1+j,k2+i));
            
            
            }}
         
         set<pair<ll,ll> > ump2;
        for(int i=-m1;i<=m1;i+=2*m1){
            for(int j= -m2;j<=m2;j+=2*m2){
              
                ump2.insert(mp(q1+i,q2+j));
                ump2.insert(mp(q1+j,q2+i));
            
            
            }}
ll count=0;
    //  for(auto x:ump){cout<<x.fi<<" "<<x.se;ce;}ce;
         for(auto x:ump){
        for(auto y:ump2){
           if(x.fi == y.fi && x.se == y.se){count++;}
        }
         }
         cout<<count;ce;
        
        
    }
return 0;
}