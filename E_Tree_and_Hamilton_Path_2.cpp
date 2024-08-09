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
        ll n;
        cin>>n;
        vector<vector<pair<ll,ll>>> adj(n);
        ll sum =  0;
        for(int  i =0;i<n-1;i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            adj[a-1].pb({b-1,w});
            adj[b-1].pb({a-1,w});
            sum+=2*w;
        } 
      
        queue<ll> q;
        q.push(0);
        vll dist(n,-1);
        dist[0] = 0;
        while(!q.empty())
        {
            ll pos  = q.front();
            q.pop();
            for(auto x:adj[pos])
            {
                if(dist[x.fi]==-1){
                    dist[x.fi] = dist[pos]+x.se;
                    q.push(x.fi);
                }
            }
        }
        queue<ll> q2;
        ll idx= 0,mx=-INF;

        rep(i,n)
        {
            if(dist[i]>mx){mx=dist[i];idx= i;}
        }
        q2.push(idx);
        vll dist2(n,-1);
        dist2[idx] = 0;
        while(!q2.empty())
        {
            ll pos  = q2.front();
            q2.pop();
            for(auto x:adj[pos])
            {
                if(dist2[x.fi]==-1){
                    dist2[x.fi] = dist2[pos]+x.se;
                        q2.push(x.fi);
                }
            }
        }
      
        cout<<sum - *(max_element(all(dist2)));
    }

    return 0;
}
