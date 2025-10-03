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
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,l,r;
        cin>>n>>l>>r;
        l--;r--;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        vll left,right,mid;
        rep(i,l)
        {
            left.pb(arr[i]);
        }
        forf(i,l,r+1)
        {
            mid.pb(arr[i]);
        }
        forf(i,r+1,n)
        {
            right.pb(arr[i]);
        }
       srt(mid);
       srt(left);
       srt(right);
    //    out(left);
    //    out(mid);
    //    out(right);
       ll val = 0;
       ll sum =  accumulate(all(mid),0ll);
       ll ans =sum;
       ll rt = mid.size()-1;
       ll lt = 0;
        while(lt<left.size() and rt>=0)
        {
            if(left[lt]<=mid[rt])
            {
                val+= mid[rt]-left[lt];
                lt++;
                rt--;
            }
            else
            {
                ans = min(ans,sum-val);
                break;
            };
       
        }
        ans = min(ans,sum-val);

        rt =0;
        lt = mid.size()-1;
        val = 0;
        while(lt>=0 and rt<right.size())
        {
            if(right[rt]<=mid[lt])
            {
                val+= mid[lt]-right[rt];
                lt--;
                rt++;
                // cout<<val<<endl;
            }
            else
            {
                ans = min(ans,sum-val);
                break;
            }
        }
        ans = min(ans,sum-val);
        cout<<ans;ce;
        // ce;
    }

    return 0;
}
