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
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);\
    std::cout.tie(nullptr);
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
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    {	//Lesgooooooo!!!!
        ll n,m,d;
        cin>>n>>m>>d;
        vector<vector<pair<ll,ll>>> adj(n+1);
        rep(i,m)
        {
            ll u,v,c;
            cin>>u>>v>>c;
            adj[u].pb({v,c});
        }
        ll left = 0 ,right = 1e9;
        ll ans = 0;
        vector<ll>par(n+1,-1);
        ll cq =0 ;

        while(right>=left)
        {
            ll mid = (left+right)/2;
            queue<ll> q;
            q.push(1);
            vector<ll> temp_par(n+1,-1);
            vector<ll> dist(n+1,INF);
            dist[1] =0 ;
            while(!q.empty())
            {
                ll val = q.front();
                q.pop();
                for(auto x:adj[val])
                {

                    if(dist[x.fi]==INF and x.se<=mid)
                    {
                        dist[x.fi] = dist[val] + 1;
                        q.push(x.fi);
                        temp_par[x.fi] = val;
                    }
                }
            }   
            // cout<<mid<<" "<<dist[n]<<endl;
            if(dist[n]<=d)
            {
                cq=1;
                par = temp_par;
                right = mid-1;
                ans = mid;
            }
            else left = mid+1;
        }
        if(cq)
        {
            vector<ll> path;
            for(int i = n;i!=-1;i=par[i])
            {
                path.pb(i);
            }
            reverse(all(path));
            cout<<path.size()-1<<endl;
            out(path);
        }
        else cout<<-1<<endl;
        // cout<<ans<<endl;
    }

    return 0;
}
