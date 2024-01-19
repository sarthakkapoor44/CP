///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
int main() {
    ll t;scanf("%lld",&t);
    while(t--)
    {   //Lesgooooooo!!!!
        ll n;scanf("%lld",&n);
        ll a[n],b[n];
        rep(i,n){scanf("%lld %lld",&a[i],&b[i]);}
        ll sum=0;
        ll val=0,min_=1e18;
        rep(i,n)
        {
        ll next = (i+1)%n;
        val=max(0ll,a[next]-b[i]);
        sum+=val;
        min_=min(a[next]-val,min_);
        }

        cout<<sum+min_;ce;
    }

    return 0;
}
