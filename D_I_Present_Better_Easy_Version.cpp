///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
   tree_order_statistics_node_update> ost;
 
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
 
    {	//Lesgooooooo!!!!
        ll n,a,b;
        cin>>n>>a>>b;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        ost bit,bit2;
        ll pt =0 ;
        if(a<b)pt=-1;
        if(a>b)pt=1;
        ll ans =0 ;
        unordered_map<ll,ll> cnt;
        vll m(n+1),c(n+1);

        rep(i,n+1)
        {
            m[i] = 2*((ll)bit.order_of_key({a,i})-cnt[a]) - ((ll)bit.size()-cnt[a]);
            c[i] = 2*((ll)bit2.order_of_key({b,i})-cnt[b]) - ((ll)bit2.size()-cnt[b]);
            if(i<n)
            {
                bit.insert({arr[i],i});
                cnt[arr[i]]++;
                bit2.insert({arr[i],i});
            }
        }
        rep(i,n+1)
        {
            ll cnt =0 ;
            for(int j =0;j<n+1;j++)
            {
                if((m[i] + pt > c[j]))
                {
                    // cnt+=  1 + ((i==j)?1:0);
                    ans+= 1 + ((i==j)?1:0);
                }

            }
            cout<<cnt;ce;
        }

      
        cout<<ans;ce;
    }

    return 0;
}

