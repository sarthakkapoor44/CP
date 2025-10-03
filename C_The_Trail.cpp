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
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<vector<ll>> grid(n,vector<ll>(m));
        rep(i,n)rep(j,m)cin>>grid[i][j];
        vector<ll> rows(n,0),cols(m,0);
        ll r = 0,c= 0;
        rep(i,n)
        {
            ll sm =0 ;
            rep(j,m)sm+= grid[i][j];
            rows[i] = sm;
        }
        rep(j,m)
        {
            ll sm =0 ;
            rep(i,n)sm+= grid[i][j];
            cols[j] = sm;
        }

        // debug(vis);
        ll fin = 0;
        // if(s[0]=='R')
        // {
        //     fin = cols[0]+1;
        // }
        // else fin = rows[0]+1;
        // cout<<fin<<endl;
        rep(i,s.size())
        {
            if(s[i] =='R')
            {
                if(r<n and c<m) grid[r][c] = fin - cols[c];
                cols[c]+= grid[r][c];
                rows[r]+= grid[r][c];
                c++;
            }
            else
            {
                if(r<n and c<m) grid[r][c] = fin - rows[r];
                cols[c]+= grid[r][c];
                rows[r]+= grid[r][c];
                r++;
            }
        }
        grid[n-1][m-1] = fin -rows[n-1];
        rep(i,n)
        {
            rep(j,m)cout<<grid[i][j]<<" ";
            ce;
        }
        
    }

    return 0;
}
