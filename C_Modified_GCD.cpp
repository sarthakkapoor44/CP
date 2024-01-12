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
const ll MODN= 1e9 + 7;
ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        ll a,b,q;
        cin>>a>>b>>q;
        ll d = gcd(a,b);
        set<ll> divisors;
        for(ll i=1;i*i<=d;i++){
            if(d%i==0){divisors.insert(i);}
        }
        for(auto x:divisors){divisors.insert(d/x);}
        // for(auto x:divisors){cout<<x<<" ";}ce;
        rep(i,q){
            ll ans=0;
            ll l,r;cin>>l>>r;
            if(r>=d){
                if(l>d){ans=-1;}
                else{ans=d;}
            }
            else{
                    auto x = divisors.lower_bound(l);
                    auto y = divisors.upper_bound(r);
                    y--;
                    if(x!=divisors.end() && *x<=r && *x>=l){
                        if(*x<=r){ans=*x;}
                        if(*y>=l)
                        {
                        ans = max(ans,*(y));
                        }
                    }
                    else{ans=-1;}
            }
            cout<<ans;ce;
        }
        
    }
return 0;
}