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
    
    
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        ll a[n],b[n];
        rep(i,n)cin>>a[i];
        rep(i,n)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        ll ans  =INF;
        rep(i,n)
        {
            ll diff = a[i]-b[0];
            ll to_add=0;
            if(diff<=0)
            {
                to_add = b[0]-a[i];
            }
            else 
            {
                to_add = m+b[0]-a[i];
            }
            ll cq=1;
            rep(j,n)
            {
                if((a[(i+j)%n]+to_add)%m != b[j]){cq=0;break;}
            }
            if(cq)ans =min(ans,to_add);
        }
        cout<<ans;ce;
    }

    return 0;
}
