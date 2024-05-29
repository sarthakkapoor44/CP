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
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 100001;
const ll modn = 998244353;


vp primeFact(ll num,ll k)
{   
    vp temp;
    ll cnt =0;
    if(num==1){return temp;}

    while(!(num%2)){num/=2;cnt++;}
    if((cnt%k)){temp.pb(mp(2,(cnt%k)));}

    for(ll i=3;i*i<=num;i++)
    {
        cnt =0;
        while(!(num%i))
        {
            num/=i;cnt++;
        }
        if((cnt%k))temp.pb(mp(i,(cnt%k)));
    }
    if(num>1){if(1%k)temp.pb(mp(num,(1%k)));}
    return temp;
}

int main() {
   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
  
       //Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        v arr(n);rep(i,n)cin>>arr[i];
        map<vector<pair<ll,ll> > ,ll> primes;
        ll ans  =0;
      
        rep(i,n)
        {
            vp temp;
            temp = primeFact(arr[i],k);
            vp temp2;
            rep(i,temp.size()){temp2.pb(mp(temp[i].fi,k-temp[i].se));}
            ans+= primes[temp2];
            primes[temp]++;
        }
      
        cout<<ans;ce;


    return 0;
}
