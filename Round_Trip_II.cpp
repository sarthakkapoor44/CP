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
bool dfs(ll pos,vector<vector<ll> >&adj,vector<ll> &visited,vector<ll> &parent,ll &start,ll &end)
{
    visited[pos]=1;
    for(auto x:adj[pos])
    {
        if(!visited[x])
        {
            parent[x]=pos;
            if(dfs(x,adj,visited,parent,start,end)) return true;
        }
        if(visited[x]==1){start= x;end =pos;return true ;}
        
    }
    visited[pos]=2;
    return false;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
   
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<ll> > adj(n);
        v visited(n,0);
        rep(i,m)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
        }
        v parent(n,-1);
        ll start =-1,end =-1;
        rep(i,n)
        {
            if(!visited[i])if(dfs(i,adj,visited,parent,start,end)){break;};
        } 
        // for(auto x:parent)cout<<x<<" ";ce;cout<<start+1;ce;

        // cout<<start<<" "<<end;ce;
        if(start==-1){cout<<"IMPOSSIBLE";}
        else {
            vector<ll> order;
            order.push_back(start);
            order.pb(end);
            while(parent[end]!=start)
            {
                end= parent[end];
                order.pb(end);
                // cout<<end<<" "<<parent[end];ce;
            }
            order.pb(start);
            reverse(all(order));
            cout<<order.size();ce;
            for(auto y: order)cout<<y+1<<" ";
        }
        
    }

    return 0;
}
