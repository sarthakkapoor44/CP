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
const ll N = 200001;
vector<vector<ll> > adj;
v path;
ll start,last;
bool find_cycle(ll pos,ll parent ,v &vis)
{
    vis[pos]=1;
    for(auto x:adj[pos])
    {
        if(!vis[x]){path[x]=pos;if(find_cycle(x,pos,vis))return true;}
        else if(vis[x]==1 && x!=parent) 
        {
            start=x;
            last=pos;
            return true;
        }
    }
    vis[pos]=2;
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
        ll n,mar,val;
        cin>>n>>mar>>val;
        start=-1;
        last=-1;
        adj.clear();
        adj.resize(n);
        path.clear();
        path.resize(n);
        rep(i,n)
        {
            ll a,b;
            cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        } 
        
        vector<ll> vis(n,0);
        find_cycle(0,-1,vis);
        queue<ll> q;
        q.push(val-1);
        v dist_val(n,-1);
        dist_val[val-1]=0;
        v cycle(n,0);
        while(last!=start)
        {
        
           cycle[last]=1;
           last = path[last];
        }
        ll val_first=-1;
        cycle[start]=1;
        while (!q.empty())
        {
            ll pos = q.front();
            q.pop();
            for(auto x: adj[pos])
            {
                if(dist_val[x]==-1)
                {
                    dist_val[x]=dist_val[pos]+1;
                    q.push(x);
                    if(cycle[x]){val_first=x;break;}
                }
            }
            if(val_first!=-1)break;
        }
        queue<ll> q1;
        q1.push(mar-1);
        v dist_mar(n,-1);
        dist_mar[mar-1]=0;
        while (!q1.empty())
        {
            ll pos = q1.front();
            q1.pop();
            for(auto x: adj[pos])
            {
                if(dist_mar[x]==-1)
                {
                    dist_mar[x]=dist_mar[pos]+1;
                    q1.push(x);
                 
                }
            }
          
        }
        bool flag=0;
       if(cycle[val-1]){flag=1;}
       else 
       {
         if(dist_mar[val_first]>dist_val[val_first])flag=1;
       }
       if(mar==val)flag=0;
        if(flag){pyes;}
        else {pno;}
        ce;
        
    }

    return 0;
}
