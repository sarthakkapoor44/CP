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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<vector<ll>> adj(n);
        rep(i,n-1)
        {
            ll a,b;cin>>a>>b;
            a--;b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vll distance(n);
        function<void(ll,ll,ll)> dfs=  [&](ll pos,ll par, ll dist)->void
        {
            distance[pos] = dist;
            for(auto x: adj[pos])
            {
                if(x== par)continue;
                dfs(x,pos,dist+1);
            }
        };
        dfs(0,0,0);
        ll a = max_element(all(distance)) - distance.begin();
        dfs(a,a,0);
        ll b = max_element(all(distance)) - distance.begin();
        vector<bool> vis(n);
        function<bool(ll,ll)> find_path = [&](ll pos,ll par)->bool{
            bool found = 0;
            if(pos==b){found=1;}
            for(auto x:adj[pos])
            {
                if(x == par)continue;
                found = found|find_path(x,pos);
            }
            if(found)vis[pos]=1;
            return found; 
        };
        find_path(a,a);
        ll mx_dist = distance[b];
        queue<ll> q;
        distance.clear();
        distance.resize(n);
        rep(i,n)
        {
            if(vis[i])q.push(i);
        }
        while(!q.empty())
        {
            ll u =q.front();
            q.pop();
            for(auto v:adj[u])
            {
                if(!vis[v])
                {
                    distance[v] = distance[u]+1;
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        ll mx2  =-INF;
        ll c;
        rep(i,n)
        {
            if(i!=a && i!=b && mx2< distance[i]){c= i;mx2 = distance[i];}
        }
        mx_dist+=mx2;
        cout<<mx_dist;ce;
        cout<<a+1<<" "<<b+1<<" "<<c+1;ce;
        // debug(a,b,distance);
        
    }

    return 0;
}
