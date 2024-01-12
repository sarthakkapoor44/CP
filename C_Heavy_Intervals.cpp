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
        vp seq;
        rep(i,2*n){
            ll a;
            cin>>a;
            if(i<n)seq.pb(mp(a,1));
            else seq.pb(mp(a,-1));
        }
        srt(seq);
        ll c[n];rep(i,n)cin>>c[i];
        // rep(i,2*n)cout<<seq[i].fi<<"->"<<seq[i].se<<" ";
        stack<ll> st;
        v interval;
        rep(i,2*n)
        {
            if(seq[i].se==1){st.push(seq[i].fi);}
            else{interval.push_back(seq[i].fi-st.top());st.pop();}
        }
        srt(interval);
        sort(c,c+n,greater<ll>());
        ll ans=0;
        rep(i,n){ans+=c[i]*interval[i];}cout<<ans;ce;
        
    }
return 0;
}