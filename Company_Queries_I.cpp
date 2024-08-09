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
 
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        ll l = ceil(log2(2e5));
        vector<vector<ll>> adj(n);
        vector<vector<ll>> succ(n,vector<ll>(l+1,-1));
        for(int i=1;i<n;i++)
        {
            ll num;cin>>num;
            adj[i].push_back(num-1);
            adj[num-1].push_back(i);
        }
        function<void(ll,ll)> dfs = [&](ll pos,ll par)->void{
            succ[pos][0] = par;
            for(int i=1;i<=l;i++)
            {
                if(succ[pos][i-1]>=0) succ[pos][i] = succ[succ[pos][i-1]][i-1]; 
            }
            for(auto x: adj[pos])
            {
                if(x==par)continue;
                dfs(x,pos);
            }
            return ;
        };
        dfs(0,-1);
        function<ll(ll,ll)> find = [&](ll pos,ll level)->ll{
            int curr = 0;
            while(level)
            {
                if((level & 1)) pos = succ[pos][curr];
                if(pos==-1)break;
                curr++;
                level >>=1;
            }
            if(pos==-1)return pos;
            else return pos +1;

        };
        rep(i,q)
        {
            ll pos,level;cin>>pos>>level;
            pos--;
            cout<<find(pos,level);ce;
        }
        
    }

    return 0;
}
