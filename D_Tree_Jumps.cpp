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
#define pll pair<ll,ll>
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
        ll n;
        cin>>n;
        vector<vector<ll>> adj(n);
        for(int i =2;i<=n;i++)
        {
            ll u;cin>>u;
            adj[u-1].pb(i-1);
            adj[i-1].pb(u-1);
        } 
        vector<vector<ll>> level;
        queue<ll>q;
        q.push(0);
        vector<bool> vis(n);
        vis[0] = true;
        while(!q.empty())
        {
            int sz = q.size();
            vector<ll> temp;
            for(int i =0 ;i<sz;i++)
            {
                ll node = q.front();
                temp.pb(node);
                q.pop();
                for(auto x:adj[node])
                {
                    if(!vis[x])
                    {

                        vis[x] =true;
                        q.push(x);
                    }
                }
            }
            level.pb(temp);
        }
        // debug(level);
        vector<ll>ans(n,0),lvl(level.size());
        for(int i =level.size()-1;i>=0;i--)
        {
            for(auto x:level[i])
            {
                if(i+1<level.size())
                {
                    (ans[x]+= lvl[i+1]%modn)%=modn;
                    if(x!=0)
                    {
                        for(auto y:adj[x])
                        {
                        ans[x] = (ans[x] - ans[y]+modn)%modn;
                        }
                    }
                }
                ans[x]++;
                (lvl[i]+=(ans[x]%modn))%=modn;
            }

        }
        // debug(ans);
        cout<<ans[0]%modn<<endl;
    }

    return 0;
}
