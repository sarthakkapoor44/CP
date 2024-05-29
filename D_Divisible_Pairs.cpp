///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
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
const ll MAXN = 1000001;

int main() {
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll x,y,n;
        scanf("%lld %lld %lld",&n,&x,&y);
        ll arr[n];
        rep(i,n){scanf("%lld",&arr[i]);}
        map<pair<ll,ll>,ll> mod;
        rep(i,n){
            mod[mp((arr[i]%x),(arr[i]%y))]+=1;
        }
        ll ans = 0;
        // for(auto itr :mod){
        //     cout<<itr.fi.fi<<" "<<itr.fi.se<<" "<<itr.se;
        //     ce;
        // }ce;
        for(auto itr :mod ){
            ll one = (x -itr.fi.fi)%x;
            ll two = itr.fi.se;
            ll val = mod[mp(one,two)];
            if(one == itr.fi.fi){ans += (val*(val-1))/2;}
            else{ans+= mod[itr.fi]*val;}
            mod[itr.fi]=0;
        }
        cout(ans);ce;
    }

    return 0;
}




