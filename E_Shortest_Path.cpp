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
    
  
    {   //Lesgooooooo!!!!
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<ll>  >adj(n+1);
        rep(i,m){ll a,b;cin>>a>>b;adj[a].pb(b);adj[b].pb(a);}
        set<vector<ll> >forbidden;
        v vect(3);
        rep(i,k){cin>>vect[0]>>vect[1]>>vect[2];forbidden.insert(vect);}
        queue<pair<ll,ll> > bfs;
        v dist(n+1,INF);
        dist[0]=0;
        dist[1] =0;
        bfs.push(mp(0,1)); // parent vertex
        vector<vector<ll> >visited(n+1,vector<ll>(n+1,0));
        visited[0][1] = 1; // initial parent vertex =1 
             v path(n+1,-1);
        while(!bfs.empty())
        {
            auto curr = bfs.front();
            bfs.pop();
            v finds;
            ll parent = curr.fi;
            ll ver = curr.se;
            finds.pb(parent);finds.pb(ver);
            ll cq=0;
            path[1]=0;
            for(auto child:adj[ver])
            {
                finds.pb(child);
                if(!forbidden.count(finds) && !visited[ver][child])
                {
                    cout<<parent<<" "<<ver<<" "<<child;ce;

                    visited[ver][child]=1;
                    dist[child]=min(dist[child],dist[ver]+1);
                    bfs.push(mp(ver,child));
                    path[child]=ver;
                    if(child==n)cq=1;
                     if(cq)break;
                }
               
                finds.pop_back();
              
            }
              if(cq)break;
        }
          ll ver  =n;
                // while(ver!=-1){
                //     cout<<ver;
                //     ver = path[ver];
                //     ce;
                // }
        for(auto x:path)cout<<x<<" ";ce;
        cout<<dist[n];ce;
    }

         
        

    return 0;
}
