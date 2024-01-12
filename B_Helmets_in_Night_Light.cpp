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
        ll n,p;
        cin>>n>>p;
        vp arr(n,mp(0,0));
        rep(i,n){ll a;cin>>a;arr[i].se=a;}
        rep(i,n){ll a;cin>>a;arr[i].fi=a;}
        srt(arr);
        ll end =n-1,curr=0;
        ll cost =0;
        //  rep(i,n){cout<<arr[i].fi<<" "<<arr[i].se;ce;}ce;
        multiset<ll> ms;
        ms.insert(p);
        rep(i,n){
            if(arr[i].se<=p){
                while(arr[i].se--){if(ms.size()==n){break;}ms.insert(arr[i].fi);if(ms.size()==n){break;}}
            }
            else{if(ms.size()==n)ms.insert(p);if(ms.size()==n){break;}}
            if(ms.size()==n){break;}
        }
        for(auto x:ms){cost+=x;}
        cout<<cost;ce;
        
    }
return 0;
}