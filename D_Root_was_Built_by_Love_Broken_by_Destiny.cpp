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
const ll N = 2e5+5;
vector<ll> fact(N);
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    fact[1]=1;
    fact[0]=1;
    for(ll i=2;i<N;i++){
        fact[i] = (((i%MODN)*(fact[i-1]%MODN))%MODN);
    }
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        // debug(n,m);
        ll ans =1; 
        vector<vector<ll>> adj(n);
        map<ll,ll> deg;
        rep(i,m){
            ll u,v;
            cin>>u>>v;
            // cout<<u<<" "<<v;ce;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        rep(i,n){
            if(deg[i]<=1)continue;
            ll cnt=0;
            for(auto x:adj[i]){
                if(deg[x]>1)cnt++;
            }
            if( cnt >2 )ans =0;
        }
        vector<ll> colors(n,-1);
        function<bool(ll,ll,vector<ll>&)> check = [&](ll pos,ll par,vector<ll> &nodes)->bool{
            nodes.pb(pos);
            for(auto x:adj[pos]){
                if(colors[x]==-1){
                    colors[x] =1-colors[pos];
                    if (!check(x,pos,nodes))return false;
                } else if (colors[x] == colors[pos]){
                    return false;
                } else if (colors[x] != colors[pos] && x != par){
                    return false;
                }
            }
            return true;
        };
        ll components =0;
        rep(i,n){
            if(colors[i]==-1){
                vector<ll> nodes;
                colors[i]=0;
                if(!check(i,-1,nodes)){
                    ans=0;
                    break;
                }
                ll val =1;
                ll pow =0;
                for(auto x:nodes){
                    if(adj[x].size()>1){
                        ll cnt =0;
                        for(auto y: adj[x]){
                            if(adj[y].size()==1){(cnt += 1)%=MODN;}
                            else pow=1;
                        }
                        (ans*= fact[cnt]%MODN)%=MODN;
                    }
                }
                if (pow) (ans*=2)%=MODN;
                (ans*=2)%=MODN;
                components+=1;
            }
            if(!ans)break;
            
        }
        (ans*= fact[components]%MODN)%=MODN;
        cout<<ans%MODN;ce;
    }

    return 0;
}
