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
void dfs(ll pos,vector<vector<ll> >&adj,v &visited,v &topo)
{   
    visited[pos]=1;
    
    for(auto x:adj[pos]){if(!visited[x])dfs(x,adj,visited,topo);}
    
    topo.pb(pos);
    return ;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<ll> > adj(n),adjt(n);
        rep(i,m)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adjt[b-1].pb(a-1);

        }
        v topo;
        vector<ll> visited(n,0);
        rep(i,n){if(!visited[i])dfs(i,adj,visited,topo);}
        reverse(all(topo));
    
        v dp(n,0);
        ll i=0;
        dp[0]=1;
        while(topo[i]!=0)i++;i++;
        for(i;i<n;i++)
        {
            for(auto x: adjt[topo[i]])
            {
               ( dp[topo[i]]+=dp[x]%MODN)%=MODN;
            }
        }
        cout<<dp[n-1];ce;
       
       
        
        
    }

    return 0;
}
