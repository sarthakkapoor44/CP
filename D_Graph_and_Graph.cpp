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
// map<pair<int,int>,set<pair<pair<int,int>,int>>> adj;
const int N = 1000;
vector<vector<bool>> vis(N,vector<bool>(N,0));
vector<vector<int>> dist(N,vector<int>(N,INT_MAX));
// set<pair<int,int>> same;
set<pair<int,pair<int,int>>> st;

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        int n,s1,s2;
        cin>>n>>s1>>s2;
        s1--;s2--;
        vector<vector<int>> g1(n),g2(n);
        int m1;cin>>m1;
        rep(i,m1)
        {
            int u,v;
            cin>>u>>v;
            g1[u-1].pb(v-1);
            g1[v-1].pb(u-1);
        }         
        int m2;cin>>m2;
        rep(i,m2)
        {
            int u,v;
            cin>>u>>v;
            g2[u-1].pb(v-1);
            g2[v-1].pb(u-1);
        }
        // vector<bool> vis1(n,false),vis2(n,false);
        // same.clear();
        // adj.clear();
        for(int i= 0 ;i<n;i++)for(int j=0 ;j<n;j++)
        {
            vis[i][j] = 0;dist[i][j] = INT_MAX;
        }
        // queue<pair<int,int>> q;
        // q.push({s1,s2});
        // vis[s1][s2] = 1;
        // while(!q.empty())
        // {
        //     auto [node1,node2] = q.front();
        //     q.pop();
        //     // if(g1[node1].size() == 0 && g2[node2].size() == 0)same.insert({node1,node2});
        //     for(auto x:g1[node1])
        //     {
        //         for(auto y:g2[node2])
        //         {
        //             if(!vis[x][y])
        //             {
        //                 vis[x][y] = 1;
        //                 q.push({x,y});
        //             }
        //             if(x == y and node1==node2)
        //             {
        //                 same.insert({x,y});
        //                 same.insert({node1,node2});
        //             }
        //             adj[{node1,node2}].insert({{x,y},abs(x-y)});
        //             // adj[{x,y}].insert({{node1,node2},abs(node1-node2)});
        //         }
        //     }
        // }


        // for(auto x:adj)
        // {
        //     cout<<x.fi.fi+1<<","<<x.fi.se+1<<": ";
        //     for(auto y:x.se)cout<<y.fi.fi+1<<","<<y.fi.se+1<<" wt: "<<y.se<<"| ";
        //     ce; 
        // }

        //  if(same.size()== 0)
        //  {
        //     cout<<-1;ce;
        //     continue;
        // }
        dist[s1][s2] = 0;
        st.clear();
        st.insert({0,{s1,s2}});
        vis[s1][s2] = 1;
        int ans = INT_MAX;
        while(!st.empty())
        {
            auto [d,cur] = *st.begin();
            st.erase(st.begin());
            auto [node1,node2] = cur;
            if(dist[node1][node2] < d)continue;
            for(auto x:g1[node1])
            {
                for(auto y:g2[node2])
                {
                    if(dist[x][y] > dist[node1][node2]+abs(x-y))
                    {
                        dist[x][y] = dist[node1][node2]+abs(x-y);
                        // if(!vis[x][y])
                        // {
                            st.insert({dist[x][y],{x,y}});
                            // vis[x][y] =1;
                        
                    }
                    if(x == y && node1 == node2)
                    {
                        ans = min(ans,dist[x][y]);
                        ans = min(ans,dist[node1][node2]);
                    }
                }
            }
        }
        if(ans ==INT_MAX)ans =-1;
        cout<<ans;
        // debug(same);
    

        ce;
    }

    return 0;
}
