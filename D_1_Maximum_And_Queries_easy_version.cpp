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
// typedef tree<int, nll_type, less<int>, rb_tree_tag,
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        rep(i,n)cin>>arr[i];
        rep(j,q)
        {   vector<ll> temp(n);
            rep(i,n)temp[i]=(ll)arr[i];
            ll k;cin>>k;
          
             ll ans=0ll;
            forb(bits,59ll,0ll)
            {
       unsigned long long val = 0ull;
            rep(i,n)
            {

               if(!(temp[i]&(1ll<<bits)))val += (unsigned long long)((1ull<<bits) - temp[i]%(1ull<<bits));
                if(val>k)break;
            }
            // cout<<val;ce;
              if(val<=k)
                {
                    k-=val;
                    ans+=(1ull<<bits);
                    rep(i,n)if(!(temp[i]&(1ll<<bits)))temp[i]+=((1ll<<bits) - temp[i]%(1ll<<bits));
                }
            
                val=0ll;
            }
   
            cout<<ans;ce;
        }
        
    }

    return 0;
}
