///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
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
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m,h;
        cin>>n>>m>>h;
        map<ll,ll> hv;
        rep(i,h)
        {
            ll u;
            cin>>u;
            u--;
            hv[u]=1;
        }
        vector<vector<pair<ll,ll>>> adj(n);
        rep(i,m)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        vector<vector<ll>> dist(2,vector<ll>(n,INF));
        dist[hv[0]][0]=0;
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
        pq.push({0,{hv[0],0}});
        while(!pq.empty())
        {
            ll ndist = pq.top().fi;
            ll omode = pq.top().se.fi;
            ll u = pq.top().se.se;
            pq.pop();
            if(dist[omode][u]<ndist)continue;
            for(auto [x,w]:adj[u])
            {
                ll nmode = omode|hv[x];
                if(dist[omode][x]> ndist + w/pow(2,omode)){
                    dist[omode][x] = ndist + w/pow(2,omode);
                    pq.push({dist[omode][x],{nmode,x}});
                }
            }
        }

        vector<vector<ll>> dist2(2,vector<ll>(n,INF));
        dist2[hv[n-1]][n-1]=0;
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq2;
        pq2.push({0,{hv[n-1],n-1}});
        while(!pq2.empty())
        {
            ll ndist = pq2.top().fi;
            ll omode = pq2.top().se.fi;
            ll u = pq2.top().se.se;
            pq2.pop();
            if(dist2[omode][u]<ndist)continue;
            for(auto [x,w]:adj[u])
            {
                ll nmode = omode|hv[x];
                if(dist2[omode][x]> ndist + w/pow(2,omode)){
                    dist2[omode][x] = ndist + w/pow(2,omode);
                    pq2.push({dist2[omode][x],{nmode,x}});
                }
            }
        }
        // debug(dist2[0],dist2[1]);
        ll ans=INF;
        rep(i,n)
        {
            ll d1  =min(dist[0][i],dist[1][i]);
            ll d2  =min(dist2[0][i],dist2[1][i]);
            ans = min(ans,max(d1,d2));
        }
        if(ans==INF)cout<<-1;
        else cout<<ans;
        ce;
    }
   
    return 0;
}
