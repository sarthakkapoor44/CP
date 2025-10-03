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
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll x,y;
        cin>>x>>y;
        if(x==y){cout<<0<<endl;continue;}
        bitset<65> a(x),b(y);
        bool f1 = 0,f2=0;
        ll msb_a = -1,msb_b = -1;
        // debug(x,y);
        for(int i=65;i>=0;i--)
        {
            if(f1==0 and a[i]==1){f1=1;msb_a=i;}
            if(f2==0 and b[i]==1){f2=1;msb_b=i;}
        }
        if(msb_a==-1 or msb_b==-1)
        {
            cout<<(1ll<<(max(msb_a,msb_b)+1))<<endl;
            continue;
        }
        ll match = 0;
        ll k1 = 0,k2= 0 ;
        for(int i=msb_a,j = msb_b;i>=0,j>=0;j--,i--)
        {
            if(a[i]!=b[j])
            {
                k1 = i+1;
                k2 =  j+1;
                break;
            }
            else match++;
        }
        debug(k1,k2);
        cout<<a<<endl;
        cout<<b<<endl;
        if(k1!=k2)
        {
            cout<<(1ll<<k1)+(1ll<<k2)<<endl;
        }
        else
        {
            // if(k1>=3)cout<<2*(1ll<<k1);
            cout<<"tba"<<endl;
        }
        
    }

    return 0;
}
