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
        ll n,k;
        cin>>n>>k;
        v arr(2*n);
        rep(i,2*n){cin>>arr[i];}
        map<ll,ll> freq1,freq2;
        rep(i,n){freq1[arr[i]]++;}
        vp left,right;
        for(auto x:freq1)
        {
            left.pb(mp(x.se,x.fi));
        }
        // freq.clear();
        forf(i,n,2*n){freq2[arr[i]]++;}
        for(auto o:freq2)
        {
            right.pb(mp(o.se,o.fi));
        }
        srt(left);srt(right);
        v l,r;
        ll end = left.size()-1;
        ll val =0;
        // rep(i,left.size())cout<<left[i].fi<<"->"<<left[i].se<<" ";ce;
        // rep(i,left.size())cout<<right[i].fi<<"->"<<right[i].se<<" ";ce;
        while(val<2*k)
        {
            if(left[end].fi==2 && right[end].fi==2 )
            {
                l.pb(left[end].se);l.pb(left[end].se);
                freq1[left[end].se]=0;
                freq2[right[end].se]=0;
                r.pb(right[end].se);r.pb(right[end].se);
                val+=2;
                end--;
            }
           else{break;}
        }
        if(l.size()<2*k)
        { 
            for(auto p:freq1){
                // cout<<p.fi<<" ";
            if(p.se==1)
            {
                l.pb(p.fi);r.pb(p.fi);
                
            }
            if(l.size()==2*k){break;}
         }
        }
    for(auto z:l)cout<<z<<" ";ce;
    for(auto y:r)cout<<y<<" ";ce;

    }

    return 0;
}
