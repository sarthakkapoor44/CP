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

vector<ll> parent,sizes;

void make_set(ll i)
{
    sizes[i]=1;
    parent[i]=i;
}
int find_set(ll i){
    if(i== parent[i])return i;
    return parent[i]=find_set(parent[i]);
}
void union_set(ll a,ll b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(sizes[a]<sizes[b]){swap(a,b);}
        sizes[a]+=sizes[b];
        parent[b]=a;
    }
}
int dfs(ll start ,ll curr,ll parent,ll len, vector<vector<pair<ll,ll> > > &mst,vector<vector<ll> > &grid)
{
    if(grid[start][curr]!=len  || grid[curr][start]!=len)return 0;
    for(auto x:mst[curr])
    {
        if(x.fi!=parent) if(!dfs(start,x.fi,curr,len+x.se,mst,grid))return 0;
    }
    return 1;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<vector<ll> > grid(n,vector<ll>(n));
        int cq =1;
        rep(i,n)rep(j,n){cin>>grid[i][j];if(!(i-j))if(grid[i][j]){cq=0;break;}}
        parent.resize(n);        
        sizes.resize(n);        
        vector<pair<ll,pair<ll,ll> > > edges;
        rep(i,n){make_set(i);}
        rep(i,n)rep(j,n)if(i!=j){edges.pb({grid[i][j],{i,j}});}
        vector<vector<pair<ll,ll> > > mst(n);
        // vector<vector<ll > > dist(n,vector<ll>(n,0));
        for(auto x:edges)
        {
            ll w=  x.fi;
            ll a= x.se.fi;
            ll b = x.se.se;
            if(!w){cq=0;break;}
            if(find_set(a)!=find_set(b))
            {
                mst[a].pb({b,w});
                mst[b].pb({a,w});
                // dist[a][b]=w;
                // dist[b][a]=w;
                union_set(a,b);
            }
        }
        rep(i,n){if(!dfs(i,i,-1,0,mst,grid)){cq=0;break;}}
        if(!cq){pno;}
        else pyes;
        ce;
        // rep(i,n)
        // {
        //     for(auto x:mst[i])
        //     {
        //         cout<<i<<" "<<x.fi<<" "<<x.se;ce;
        //     }
        // }
        // for(auto t:dist){for(auto y:t)cout<<y<<" ";cout<<endl;}
    }

    return 0;
}
