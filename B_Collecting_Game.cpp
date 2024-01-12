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
        vp vect;
        rep(i,n){ll a,b;cin>>a;vect.pb(mp(a,i));}
        srt(vect);
        // rep(i,n){cout<<vect[i].fi<<" ";}ce;
        v ordered;
        rep(i,n){ordered.pb(vect[i].fi);}
        // ll sum =0;
        vp ans;
        rep(i,n){ans.pb(mp(0,0));}
        ll sum[n];
        memset(sum,0,sizeof(sum));
        rep(i,n){
            if(i==0){sum[0]=ordered[i];}
            else{sum[i]= sum[i-1]+ordered[i];}
        }
        // rep(i,n){cout<<sum[i]<<" ";}ce;
        forb(i,n-1,0){
            ll index= upper_bound(ordered.begin(),ordered.end(),sum[i])-ordered.begin()-1;
            ans[i].fi= vect[i].se;
            ans[i].se = index;
            ans[i].se = ans[index].se;
        }
    srt(ans);
        rep(i,n){cout<<ans[i].se<<" ";}ce;
    }
return 0;
}