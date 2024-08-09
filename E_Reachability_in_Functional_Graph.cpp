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
ll start=-1,last=-1;
ll N = 2e5;
vector<ll> vis(N,0),vis2(N,0);
vector<ll> paths(N,0);
vector<ll> topo;
vector<vector<ll >> adj(N);
vector<ll> dp(N,-1);
// vector<ll> cycle_nodes(N,0);
bool cycle(ll pos)
{
    vis[pos]=1;
    for(auto x:adj[pos])
    {
        if(!vis[x])
        {
            paths[x]=pos;
            if(cycle(x)){vis[pos]=2;return true;}
        }
        else if(vis[x]==1)
        {
            vis[pos]=2;
            start = x;last=pos;
            return true;
        }
    }
    vis[pos]=2;
    return false;
}
void toposort(ll pos)
{
    vis2[pos]=1;
    for(auto x:adj[pos])
    {
        if(!vis2[x]){toposort(x);}
    }
    vis2[pos]=2;
    topo.pb(pos);
}
void dfs(ll pos)
{
    if(dp[pos]!=-1)return ;
    dp[pos]=1;
    for(auto x: adj[pos])
    {
        dfs(x);
        dp[pos] += dp[x];
    }
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        rep(i,n)
        {
            ll a;
            cin>>a;
            adj[i].pb(a-1);
        }
        
        rep(i,n)
        {
          if(!vis2[i])toposort(i);
        }
        reverse(all(topo));
        // for(auto x:topo)cout<<x<<" ";ce;
        rep(i,n)
        {

            ll pos  = topo[i];
            vector<ll> cycle_nodes;
            if(!vis[pos])
            {   
                start=-1,last=-1;
                ll cy_len  =0;
                if(cycle(pos))
                { 
                    while(last !=start)
                    {
                        cycle_nodes.pb(last);
                        last =paths[last];
                        cy_len ++;
                    }
                    cycle_nodes.pb(last);
                    cy_len++;
                }
                for(auto x:cycle_nodes){dp[x]=cy_len;}
                dfs(pos);
            }
        }
        ll ans = 0;
        rep(i,n){ans+=dp[i];}
        cout<<ans;ce;
    }

    return 0;
}
