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
        ll n,k,q;
        cin>>n>>k>>q;
        vector<vector<ll>> arr(n,vector<ll>(k));
        rep(i,n)rep(j,k)cin>>arr[i][j];
        forf(i,1,n)
        {
            rep(j,k)arr[i][j] = (arr[i][j]|arr[i-1][j]);
        }
        vector<vector<ll>> grid(k,vector<ll>(n));
        rep(i,n)rep(j,k)grid[j][i]=arr[i][j];
        // debug(grid);
        rep(i,q)
        {
            ll cq=1;
            ll qq;
            cin>>qq;
            ll max_col =1,min_col=n;
            rep(j,qq)
            {
                ll row,val;char sign;
                cin>>row>>sign>>val;
                row--;
                if(cq)
                {
                    if(sign=='>')
                    {
                        auto x = upper_bound(all(grid[row]),val)-grid[row].begin();
                        if(x==n){cq=0;}
                        else
                        {
                            max_col = max(max_col,(ll)(x+1));
                        }
                    }
                    else if(sign == '<')
                    {
                        auto x = lower_bound(all(grid[row]),val)-grid[row].begin();
                        if(x==n)x--;
                        // if(x==0)cq=0;
                        if(grid[row][x]>=val)
                        {
                            if(x==0)cq=0;
                            else x--;
                        }
                        min_col = min(min_col,(ll)(x+1));
                    }
                }
            }
            // cout<<i+1<<" ";
            if(!cq)cout<<-1;
            else
            {
                // cout<<min_col<<" "<<max_col;ce;
                if(max_col<=min_col && max_col<=n && max_col>=1 && min_col<=n && min_col>=1)cout<<min(max_col,min_col);
                else cout<<-1;
            }
            ce;
        }
    }

    return 0;
}
