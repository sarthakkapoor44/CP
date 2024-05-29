///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000ll
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
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 10001;


int main() {

    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        v dist(n,0);
        rep(i,n){cin(dist[i]);}
        forf(i,1,n){dist[i]-=dist[i-1];}
        ll m;cin(m);
        v lit(m,0);
        rep(i,n){cin(lit[i]);}
        ll d,k;cin(d);cin(k);
        dist.pb(d-dist[n-1]);
        lit.pb(0);
        
    }

    return 0;
}

