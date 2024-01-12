#include<bits/stdc++.h>
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
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        set<pair<ll,ll> > points;
        
        ll ans =1;
        ll left=0,right=0,up=0,down =0;
        rep(i,n){
            ll a,b;
            cin>>a>>b;
            if(a<0){left=1;}
            else{if(a>0){right =1;}}
            if(b<0){down=1;}
            else{if(b>0){up=1;}}
            
        }
        if(up==1 && down==1 && right ==1 && left ==1){ans=0;}
        if(ans){pyes;}else{pno;}ce;
    }
return 0;
}