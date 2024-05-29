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
        ll n,k,q;
        cin>>n>>k>>q;
        v dist(k+1);dist[0]=0;forf(i,1,k+1)cin>>dist[i];
        v time(k+1);time[0]=0;forf(i,1,k+1)cin>>time[i];
        rep(i,q)
        {
            ll d;cin>>d;
             ll idx= lower_bound(all(dist),d)-dist.begin();
            if(dist[idx]==d){cout<<time[idx]<<" ";}
            else if(dist[idx]>d)
            {
                ll delta_time = time[idx]-time[idx-1];
                ll delta_dist = dist[idx]-dist[idx-1];
                // cout<<delta_dist<<" "<<delta_time;ce;
                double speed = (double)(delta_dist/(delta_time*1.0));
                double extra_time = (d-dist[idx-1])/speed;
                // cout<<speed;ce;
                ll time_taken =  time[idx-1]+ extra_time;
                cout<<time_taken<<" ";
            }
            
        }
         ce;
        
    }

    return 0;
}
