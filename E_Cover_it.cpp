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
        ll n,m;
        cin>>n>>m;
        vector<vector<ll > >adj(n);
        rep(i,m)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        v colors(n,-1);
        vector<vector<ll> > cols(2);
        queue<ll> bfs;
        bfs.push(0);
        colors[0]=0;
        cols[0].pb(0);
        while(!bfs.empty())
        {
            ll pos  =  bfs.front();bfs.pop();
            for(auto x:adj[pos])
            {
                if(colors[x]==-1)
                {
                     colors[x] = colors[pos]^1;
                     cols[colors[x]].pb(x);
                     bfs.push(x);
                }
            }
        }
        if(cols[0].size()<cols[1].size()){cout<<cols[0].size();ce;for(auto x:cols[0])cout<<x+1<<" ";}
        else {cout<<cols[1].size();ce;for(auto x:cols[1])cout<<x+1<<" ";}
        ce;
    }

    return 0;
}


