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
        v arr(n);
        ll pos =0 ;
        rep(i,n){cin>>arr[i];if(arr[i]==1)pos=i;}
        vp arr1,arr2;
        if(pos%2)
        {
            for(int i=1;i<n;i+=2){arr2.pb(mp(arr[i],i));}
            if(!((n-1)%2))arr2.pb(mp(arr[n-1],n-1));
            for(int i=0;i<n-1;i+=2)arr1.pb(mp(arr[i],i));
        }
        else 
        {
            for(int i=1;i<n-1;i+=2){arr1.pb(mp(arr[i],i));}
            rep(i,n)
            {
                if(!(i%2) || i==n-1){arr2.pb(mp(arr[i],i));}
            }
        }
        sort(all(arr1));
        sort(all(arr2));
        v perm(n);
        ll val =n;
        rep(i,arr1.size())
        {
            perm[arr1[i].se] = val;
            val--;
        }
        rep(i,arr2.size())
        {
            perm[arr2[i].se] = val;
            val--;
        }
       rep(i,n)cout<<perm[i]<<" ";ce;
        
    }


    return 0;
}
