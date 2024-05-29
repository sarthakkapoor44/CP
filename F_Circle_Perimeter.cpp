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
    v squares;
    forf(i,1,MAXN)
        {
            squares.pb(i*i);
        }
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll r;
        cin>>r;
      
        ll val =0;
        forf(i,1,r+1)
        {
            ll idx_lower = min(r,ll(lower_bound(all(squares),r*r-i*i)-squares.begin()));
            ll idx_upper = min(r,ll(lower_bound(all(squares),(r+1)*(r+1)-i*i)-squares.begin()));
            // ll idx_dup = lower_bound(all(squares),i*i)-squares.begin();
            // if(squares[idx_dup]==i*i && idx_dup>=idx_lower && idx_dup<idx_upper ){val--;}
            val+=idx_upper-idx_lower;
        }
        cout<<val*4+4;ce;
        
    }

    return 0;
}
