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
        ll n,m,k;
        cin>>n>>m>>k;
        vll arr(n),b(m);
        rep(i,n)cin>>arr[i];
        rep(i,m)cin>>b[i];
        vector<vector<ll>> grid(n,vector<ll>(m+1,INF));
        vector<ll> perm((1ll<<m));

        rep(i,(1ll<<m))
        {
            bitset<10> x = i;
            ll num = (1ll<<30)-1;
            rep(j,m)
            {
                if(x[j])
                {
                    num&=b[j];
                }
            }
            perm[i] = num;
        }
        // cout<<perm[0];ce;
        
        rep(i,n)
        {
            rep(j,(1ll<<m))
            {
                ll cnt = __builtin_popcountll(j);
                grid[i][cnt] = min(grid[i][cnt],arr[i]&perm[j]);
            }
        }

        // debug(grid);

        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>> > pq;
        rep(i,n)
        {
            for(int j = m ;j>=1;j--)
            {
                grid[i][j] = grid[i][j-1] - grid[i][j];
            }
        }
      

        rep(i,n)
        {
            pq.push({grid[i][1],{i,1}});
        }

        ll sum = accumulate(all(arr),0ll);
    
        rep(i,k)
        {
            ll num = pq.top().fi;
            ll idx = pq.top().se.fi;
            ll order = pq.top().se.se;
            if(!pq.empty())pq.pop();
            sum-=num;
            if(order < m)
            {
                pq.push({grid[idx][order+1],{idx,order+1}});
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
