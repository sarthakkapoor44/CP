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
#define pyes cout<<"Yes"
#define pno cout<<"No"
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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m)),b(n,vector<int>(m));
        rep(i,n)rep(j,m)cin>>a[i][j];
        rep(i,n)rep(j,m)cin>>b[i][j];
        vector<pll> row(n),col(m);
        bool cq = 1;
        rep(i,n)
        {
            ll val = 0;
            ll cnta = 0,cntb = 0;
            rep(j,m)
            {
                {
                    val^=a[i][j];
                    cnta+=a[i][j];
                    cntb+=b[i][j];
                }
            }
            if(val == 0 && !(cnta-cntb<=1 and cnta-cntb>=0)){continue;}
            else if(val == 1 && !(cntb-cnta<=1 and cntb-cnta>=0)){continue;}
            else
            {
                rep(j,m)a[i][j] = b[i][j];
            }
            
        }
        // debug(a,b);
        rep(i,m)
        {
            ll val = 0;
            ll cnta = 0,cntb = 0;
            rep(j,n)
            {
                {
                    val^=a[j][i];
                    cnta+=a[j][i];
                    cntb+=b[j][i];
                }
            }
            if(val == 0 && !(cnta-cntb<=1 and cnta-cntb>=0)){continue;}
            else if(val == 1 && !(cntb-cnta<=1 and cntb-cnta>=0)){continue;}
            else
            {
                rep(j,n)a[j][i] = b[j][i];
            }
        }
        rep(i,n)rep(j,m)if(a[i][j]!=b[i][j])cq = 0;
        if(cq)pyes;
        else pno;
    }

    return 0;
}
