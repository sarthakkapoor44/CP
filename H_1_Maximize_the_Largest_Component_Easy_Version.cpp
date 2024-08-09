///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        ll numComp =0;
        vector<string>grid(n);
        rep(i,n)cin>>grid[i];
        vector<vector<int> > vis(n,vector<int>(m,0));
        vector<pair<int,int>> dir  = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<ll> compSize;
        ll curr =0;

        function<void(ll,ll)> dfs = [&](ll i,ll j)->void
        {
            vis[i][j] = numComp;
            for(auto d:dir)
            {
                ll ni = d.fi+i;
                ll nj = d.se+j;
                if(ni<n && nj<m && ni>=0 && nj>=0 && !vis[ni][nj] && grid[ni][nj]=='#')
                {
                    curr++;
                    dfs(ni,nj);
                }
            }
            return;
        };
     
        rep(i,n)
        {
            rep(j,m)
            {
                curr =0;
                if(grid[i][j]=='#' && !vis[i][j])
                {
                    curr=1;
                    numComp++;
                    dfs(i,j);
                }
                if(curr)compSize.push_back(curr);
            }
        }
        ll mx_ans  =0;
        set<ll> done;
        rep(i,n)
        {
            done.clear();
            ll count = 0;
            rep(j,m)
            {
                if(vis[i][j]!=0 && !done.count(vis[i][j]))
                {
                    count+= compSize[vis[i][j]-1];
                    done.insert(vis[i][j]);
                }
                else if(!vis[i][j])
                {
                    if(i+1<n && vis[i+1][j] && !done.count(vis[i+1][j]))
                    {
                        done.insert(vis[i+1][j]);
                        count+= compSize[vis[i+1][j]-1];
                    }

                    if(i-1>=0 && vis[i-1][j] && !done.count(vis[i-1][j]))
                    {
                        done.insert(vis[i-1][j]);
                        count+= compSize[vis[i-1][j]-1];
                    }
                    count++;
                }
            }
            mx_ans = max(mx_ans,count);
        }

        rep(i,m)
        {
            done.clear();
            ll count = 0;
            rep(j,n)
            {
                if(vis[j][i]!=0 && !done.count(vis[j][i]))
                {
                    count+= compSize[vis[j][i]-1];
                    done.insert(vis[j][i]);
                }
                else if(!vis[j][i])
                {
                    if(i+1<m && vis[j][i+1] && !done.count(vis[j][i+1]))
                    {
                        done.insert(vis[j][i+1]);
                        count+= compSize[vis[j][i+1]-1];
                    }

                    if(i-1>=0 && vis[j][i-1] && !done.count(vis[j][i-1]))
                    {
                        done.insert(vis[j][i-1]);
                        count+= compSize[vis[j][i-1]-1];
                    }
                    count++;
                }
            }
            mx_ans = max(mx_ans,count);
        }

        cout<<mx_ans;
        ce;
    }

    return 0;
}
