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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,m,q;
        cin>>n>>m>>q;
        vll a(n),b(m);
        rep(i,n)cin>>a[i];
        rep(i,m)cin>>b[i];
        ll s1 = accumulate(all(a),0ll);
        ll s2 = accumulate(all(b),0ll);
        rep(i,n)a[i] = s1-a[i];
        rep(i,m)b[i] = s2-b[i];

        srt(a);
        srt(b);
        // debug(a,b);  

        rep(i,q)
        {
            ll x;
            cin>>x;
            // cout<<x<<" ";
            ll cq=0;
            for(ll i = 1;i*i<=abs(x);i++)
            {
                // if(i> min(m,n))break;
                if((x%i) == 0)
                {
            
                    auto cnt1 = lower_bound(all(a),(ll)i);
                    auto cnt2 = lower_bound(all(b),(ll)i);
                    auto cnt3 = lower_bound(all(a),(ll)x/i);
                    auto cnt4 = lower_bound(all(b),(ll)x/i);

                    auto cnt11 = lower_bound(all(a),-i);
                    auto cnt21 = lower_bound(all(b),-i);
                    auto cnt31 = lower_bound(all(a),(ll)-x/i);
                    auto cnt41 = lower_bound(all(b),(ll)-x/i);

                    if(cnt1!=a.end() and cnt4!=b.end() and (*cnt1) * (*cnt4) == x)
                    {
                        cq=1;break;
                    }
                    if(cnt2!=b.end() and cnt3!=a.end() and (*cnt2) * (*cnt3) == x)
                    {
                        cq=1;break;
                    }
                    if(cnt11!=a.end() and cnt41!=b.end() and (*cnt11) * (*cnt41) == x)
                    {
                        cq=1;break;
                    }
                    if(cnt21!=b.end() and cnt31!=a.end() and (*cnt21) * (*cnt31) == x)
                    {
                        // cout<<*cnt21<<" "<<*cnt31<<endl;
                        cq=1;break;
                    } 

                }
            }
            if(!cq)pno;
            else pyes;
            ce;
        }      
        
    }

    return 0;
}
