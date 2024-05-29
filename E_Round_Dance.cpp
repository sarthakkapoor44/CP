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
void dfs(ll pos,vector<v >&adj, v &visited,ll &comp,ll &cyc,ll parent)
{   
    if(!visited[pos])
    {   
        ++comp;
        visited[pos]=1;
        for(auto x:adj[pos])
        {
        if(x!=parent) dfs(x,adj,visited,comp,cyc,pos);
        }
        visited[pos]=2;
    }
    else if(visited[pos]==1)cyc=1;
}
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
        vector<v > adj(n);
        rep(i,n){
            adj[i].pb(arr[i]-1);
            adj[arr[i]-1].pb(i);
        }
        // rep(i,n){
        //     cout<<i+1<<"->";
        //     for(auto x:adj[i])cout<<x+1<<" ";ce;
        // }
        v visited(n,0); // 0:unvisited 1:exploring  2:explored
        ll tot= 0;
        ll cycles=0;
        rep(i,n)
        {   ll comp = 0;
            ll cyc = 0;
            if(!visited[i]){dfs(i,adj,visited,comp,cyc,-1);tot++;if(cyc)cycles++;}
            
        }
    // cout<<tot<<" "<<cycles;ce;
    ll  min =cycles;
    if(tot-cycles)min++;
       cout<<min<<" "<<tot;ce;
    }


    return 0;
}
