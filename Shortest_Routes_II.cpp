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
        ll n;
        cin>>n;
        vp cost(n);
        vector<ll> unsort(n);
        set<ll> str;
        rep(i,n)
        {
            
            cin>>unsort[i];
            str.insert(unsort[i]);
            cin>>cost[i].fi;
            cost[i].se = i;
        }
        srt(cost);
        v ans;
        forb(i,n-1,0)
        {
            ll idx = cost[i].se;
            ll val =  unsort[idx];
            auto x = str.lower_bound(val);
            if(x==(--str.end())){str.erase(val);}
            else{ans.pb(i);}
        }
        cout<<ans.size();ce;
        forb(i,ans.size()-1,0){cout<<ans[i]+1<<" ";}ce;
    }
        

    return 0;
}
