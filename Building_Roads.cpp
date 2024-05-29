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
void dfs(ll pos,vector<vector<ll> > &adj, v &visited,v &temp)
{
    
    if(!visited[pos])
    {   
        visited[pos]=1;
        temp.pb(pos);
        for(auto x:adj[pos])
        {
            dfs(x,adj,visited,temp);
        }
    }
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
        rep(i,m)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        v visited(n,0);
        vector<v > con;
        rep(i,n)
        {
        v temp;
        if(!visited[i])dfs(i,adj,visited,temp);
       if(temp.size()) con.pb(temp);
        }
        vp ans;
       
        rep(i,con.size()-1)
        {
            ans.pb(mp(con[i][con[i].size()-1],con[i+1][0]));
        }
        cout<<ans.size();ce;
        for(auto x:ans){
            cout<<x.fi+1<<" "<<x.se+1;ce;
        }
    }

    return 0;
}
