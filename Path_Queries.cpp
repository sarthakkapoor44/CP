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

const ll N =2e5;
vector<ll> t(4*N);
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum_seg(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return sum_seg(v*2, tl, tm, l, min(r, tm))
           + sum_seg(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        vector<vll> adj(n);
        rep(i,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);

        }
        vll dft,size(n),sum;
        map<ll,ll> idx;
        ll cnt =0 ;
        function<ll(ll,ll,ll)> dfs = [&](ll pos,ll par,ll psum)->ll{
            dft.pb(pos);
            psum+= arr[pos];
            sum.pb(psum);
            ll sub_sum = 1;
            idx[pos]  = cnt++;
            for(auto x:adj[pos])
            {
                if(x==par)continue;
                sub_sum+= dfs(x,pos,psum);
            }
            size[pos] = (sub_sum);
            return sub_sum;
        };
        dfs(0,0,0);
        // debug(dt,size,sum);
        ll diff[n];
        diff[0] = sum[0];
        forf(i,1,n)
        {
            diff[i] = sum[i]-sum[i-1];
        }
        // debug(diff);
        build(diff,1,0,n-1);
        rep(i,q)
        {
            ll type;
            cin>>type;
            if(type==1) 
            {
                ll node,val;
                cin>>node>>val;
                node--;
                ll temp = node;
                node = idx[node];
                ll nd = val-arr[temp];
                arr[temp]= val;
                update(1,0,n-1,node,nd);
                if(node+size[temp]<n)update(1,0,n-1,node+size[temp],-nd);
                
            }
            else
            {
                ll node;cin>>node;
                node = idx[node-1];
                cout<<sum_seg(1,0,n-1,0,node);ce;
            }
        }
    }

    return 0;
}
