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
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> grid(n,vector<ll>(m));
        rep(i,n)rep(j,m)cin>>grid[i][j];
        map<ll,ll> cnt;
        vector<pll> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        ll ans =0 ;
        bool cq= 0;
        // debug(grid);
        rep(i,n)
        {
            rep(j,m)
            {
                if(cnt[grid[i][j]]==0){cnt[grid[i][j]]=1;ans++;}
                for(auto d:dir)
                {
                    ll nr = d.fi+ i;
                    ll nc = d.se+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m)
                    {
                        if(grid[i][j]== grid[nr][nc])
                        {
                            // debug(i,j,nr,nc,grid[i][j],grid[nr][nc]);
                            if(cnt[grid[i][j]]!=2)ans++;
                            cnt[grid[i][j]]=2;
                            cq=1;
                        }
                    }
                }
            }
        }
        if(cq)cout<<ans-2;
        else cout<<ans-1;
        ce;
    }

    return 0;
}
