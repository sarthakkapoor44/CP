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
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n)cin>>arr[i];
        map<ll,v> adj;
        rep(i,n)adj[arr[i]].pb(i);
        ll mx_val =1;
        ll a = arr[0];
        ll l=0,r=0;
        ll lf=l,rf=r;
        for(auto x:adj)
        {   
            ll init=1;
            l = x.se[0];r=l;
            rep(i,x.se.size()-1)
            {
                if(2+init-(x.se[i+1]-x.se[i])<1){init =1ll;l=x.se[i+1];r=l;}
                else {init = 2+init-(x.se[i+1]-x.se[i]);}
                if(2+init-(x.se[i+1]-x.se[i])>mx_val){mx_val =max(2ll+init-(x.se[i+1]-x.se[i]),mx_val);a=x.fi;r=x.se[i+1];lf=l;rf=r;}
               
            }
        }
        // cout<<mx_val;ce;
        cout<<a<<" "<<lf+1<<" "<<rf+1;ce;
        
    }

    return 0;
}
