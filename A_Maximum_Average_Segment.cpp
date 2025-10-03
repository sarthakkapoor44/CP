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
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
   
    {	//Lesgooooooo!!!!
        ll n,d;
        cin>>n>>d;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        long double left = -1,right = 100;
        // long double ans = 0 ;
        ll l = 0,r = 0;
        long double ans  = 0 ;
        while(right - left > 1e-8)
        {
            long double mid =  (left+right)/(2.0);
            vector<pair<long double,ll>> temp(n);
            bool cq = false ;
            long double m = 1e9;
      
            rep(i,n)
            {
                temp[i].fi = arr[i] - mid + (i>0?temp[i-1].fi:0);
                temp[i].se = i;
                if(i-d+1 >= 0)
                {
                    long double rem =0 ;
                    ll lef = 0;
                    if(i-d>=0)
                    {
                        rem = temp[temp[i-d].se].fi;
                        lef = temp[i-d].se+1;
                    }
                    if(temp[i].fi >= rem)
                    {
                        cq = true;
                        l = lef;
                        r = i;
                        break;
                    }
                }
                if(temp[i].fi < m)
                {
                    m = temp[i].fi;
                }
                else 
                {
                    temp[i].se = temp[i-1].se;
                }
            }
            if(cq)
            {
                ans = mid;
                left = mid;
            }
            else 
            {
                right = mid;
            }
            // cout<<left<<" "<<right<<" "<<mid<<endl;
        }
        // cout<<ans<<endl;
        cout<<l+1<<" "<<r+1<<endl;
    }

    return 0;
}
