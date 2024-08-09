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

const ll N  = 2*1e5;
vector<ll> parent(N),ranks(N);
void make_set(ll i)
{
    parent[i] =i;
    ranks[i]=1;
    
}
ll find_set(ll &i)
{
    if(i==parent[i])return i;

    return parent[i] = find_set(parent[i]);
 
}

void union_set(ll &a,ll &b)
{
    a =find_set(a);
    b=find_set(b);
    if(ranks[a]<ranks[b])swap(a,b);
    ranks[a]+=ranks[b];
    parent[b] =a ;
    return ;
}
ll start=-1,last=-1,min_edge = 0;
vector<vector<pair<ll,ll>> > adj;
vector<pair<ll,ll> > paths;
bool dfs(ll pos,ll&destination,vector<ll> &vis)
{
    vis[pos]=1;
    if(pos==destination)return true;
    for(auto x:adj[pos])
    {
        if(!vis[x.fi]){paths[x.fi] = {pos,x.se};if(dfs(x.first,destination,vis))return true;}
        
    }
    return false;
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
        ll n,m;
        cin>>n>>m;
        adj.clear();
        adj.resize(n);
        paths.clear();
        paths.resize(n);
        vector<vector<ll> > edges;
        rep(i,m)
        {
            ll a,b,w;cin>>a>>b>>w;
            edges.push_back({w,a-1,b-1});
        }
        sort(edges.begin(),edges.end(),greater<vector<ll> >());
        rep(i,n)make_set(i);
        start=-1,last=-1;
        vector<ll> vis(n,0);
        min_edge=INF;
        rep(i,m)
        {
            ll a = edges[i][1];
            ll b = edges[i][2];
            ll w= edges[i][0];
            if(find_set(a)==find_set(b))
            {
                start=a;last =b;
                min_edge =w;
            }
            else
            {   
                adj[a].pb({b,w});
                adj[b].pb({a,w});
                union_set(a,b);
            }
        }

        dfs(start,last,vis);
        vector<ll> cycle_nodes;
        while(last!=start)
        {
            
            cycle_nodes.pb(last);
            last=paths[last].first;
        }
       
        cycle_nodes.pb(last);
        cout<<min_edge<<" "<<cycle_nodes.size();ce;
        for(auto x:cycle_nodes)cout<<x+1<<" ";
        ce;

        
    }

    return 0;
}
// 