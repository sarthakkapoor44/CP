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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
    ll max_bits =30;
    vll arr(2,0);
    for(int i=0;i<max_bits;i+=2)
    {
        arr[0] += (1ll<<i);
        arr[1] += (1ll<<(i+1));
    }
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll a,b,m;
        cout<<arr[0]<<endl;
        cout.flush();
        cin>>a;
        cout<<arr[1]<<endl;
        cout.flush();
        cin>>b;
        a -= 2*arr[0];
        b -= 2*arr[1];
        ll ans =0 ;
        cout<<'!'<<endl;
        cout.flush();
        cin>>m;
        bitset<32> mm(m);
        bitset<32> aa(a);
        bitset<32> bb(b);
        vector<ll> cnt(32);
        for(int i=0;i<max_bits+1;i++)
        {
            if(i%2==0)
            {

                if(bb[i]==1)cnt[i]=1;
                else if(bb[i+1]==1)cnt[i]=2;
            }
            else {
                if(aa[i]==1)cnt[i]=1;
                else if(aa[i+1]==1)cnt[i]=2;
            }
                
        }
        for(int i=0;i<max_bits+1;i++)
        {
            if(mm[i] == 1)ans+=2*(1ll<<i);
            else
            {
               ans+=cnt[i]*(1ll<<i);
            }
        }
        cout<<ans<<endl;
        cout.flush();
    }

    return 0;
}
