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
        vll arr(n);

        rep(i,n)cin>>arr[i];
        vector<vector<ll> > adj(n);
        ll ans = 0 ;
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        vector<map<ll,ll>> dp(n);
        function<void(ll,ll)> dfs= [&](ll pos,ll par)->void{
            map<ll,vector<ll>> child;
            for(auto x: adj[pos])
            {
                if(x==par)continue;
                dfs(x,pos);
                for(auto y: dp[x])
                {
                    child[y.fi].pb(y.se);
                }
            }
            for(auto m:child)
            {
                if((arr[pos]%m.fi)== 0)
                {
                    ll mx1= 0 ,mx2 = 0 ;
                    while((arr[pos]%m.fi)== 0)arr[pos]/=m.fi;
                    for(auto val:m.se)
                    {
                        if(val>mx1){swap(mx1,mx2);mx1=val;}
                        else if(val>mx2)mx2=val;
                    }
                    ans = max(ans,mx1+mx2+1);
                    dp[pos][m.fi] =mx1+1;
                }
            }
            if(arr[pos]>1)
            {
                for(int i=2;i*i<=arr[pos];i++){
                    if((arr[pos]%i)==0)
                    {
                        while((arr[pos]%i)==0)arr[pos]/=i;
                        dp[pos][i]=1;
                        ans= max(ans,1ll);
                    }
                }
            }
            if(arr[pos]>1ll)
            {
                dp[pos][arr[pos]]=1ll;
                ans= max(ans,1ll);
            }
           
        };
        dfs(0,0);
        cout<<ans;ce;
    }

    return 0;
}
