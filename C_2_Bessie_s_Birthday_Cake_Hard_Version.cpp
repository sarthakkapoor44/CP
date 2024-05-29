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
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,x,y;cin>>n>>x>>y;
        v arr(x);
        v final;
        rep(i,x){cin>>arr[i];}
        ll ans  =0;
        ll last = arr[0];
        ll final_vertices = x;
        srt(arr);
        v nde,ndo;
        rep(i,x)
        {
             ll next_dist = (arr[(i+1)%x]-arr[i]+n)%n;
             last= arr[(i+1)%x];
             if(next_dist==2){ans++;}
             if(next_dist>2 && y)
             {
               if((next_dist%2)) ndo.pb(next_dist);
              else nde.pb(next_dist);
            }

        }
        srt(ndo);
        srt(nde);
       for(auto x:ndo)
       {
        cout<<x<<" ";
        if(y){
        ll to_add  = min(y,(x-1)/2);
                final_vertices+=to_add;
                ll dist =  to_add*2;
                ans+=to_add;
                ans++;
                y-=to_add;
        }
       }
       ce;
        for(auto x:nde)
       {
        cout<<x<<" ";
        if(y){
        ll to_add  = min(y,(x-1)/2);
                final_vertices+=to_add;
                ll dist =  to_add*2;
                ans+=to_add;
                y-=to_add;
        }
       }

ce;
        ans+=final_vertices-2;
        cout<<ans;ce;
    }

    return 0;
}
 
 