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
void dfs1(ll pos,v &visited,vector<vector<ll> >&adj,stack<ll> &finish)
{
    if(!visited[pos])
    {
        visited[pos]=1;
        for(auto x:adj[pos]){dfs1(x,visited,adj,finish);}
        finish.push(pos);
    }
    return ;
}

void dfs2(ll pos,v &visited,vector<vector<ll> >&adjT)
{
      if(!visited[pos])
    {
        visited[pos]=1;
        for(auto x:adjT[pos]){dfs2(x,visited,adjT);}
       
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
        vector<vector<ll> >adj(n);
        rep(i,m)
        {
            ll a,b;cin>>a>>b;adj[a-1].pb(b-1);
        }
        v visited(n,0);
        stack<ll> finish;
   
        rep(i,n)
        {
            if(!visited[i])dfs1(i,visited,adj,finish);
        }
        visited.clear();
        rep(i,n)visited.pb(0);
        vector<vector<ll > >adjT(n);
        
        rep(i,n)
        {
            for(auto x:adj[i]){adjT[x].pb(i);}
        }
         v comps;
        while(!finish.empty())
        {
            ll pos  = finish.top();
            finish.pop();
            if(!visited[pos]){dfs2(pos,visited,adjT);comps.pb(pos);}
        }
        if(comps.size()>=2){pno;ce;cout<<comps[1]+1<<" "<<comps[0]+1;}
        else{cout<<"YES";}ce;
    }

    return 0;
}
