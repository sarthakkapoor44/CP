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
        ll n;
        cin>>n;
        vector<ll> arr(n);
        rep(i,n)cin>>arr[i];
        srt(arr);
        vector<ll> prefix(n);
        rep(i,n){
            prefix[i] = (i>=1?prefix[i-1]:0)+ arr[i];
        }
        ll sum = accumulate(all(arr),0ll);
        ll ans = sum;
        function<bool(ll,ll)> check = [&](ll value,ll index)->bool{
            if(value < 0 || value >=n )return 0 ;
            if(value == 0 ){return 1;}
            if(value + index < n && value -1 >=0 && value-1<index){
                if(arr[value+index]+arr[value-1] <= 2*arr[index])return 1;
            }
            return 0;
        };
        for(ll i =0;i<n;i++){
            ll median = arr[i];
            ll right = min(i,n-i-1),left = 0,range = 0;
            while(left<=right){
                ll mid = (left+right)/2;
                if(check(mid,i)){
                    range =mid;
                    left = mid+1;
                } else{
                    right=mid-1;
                }
            }
            if(range){
                ll val = 2*range*arr[i] - (prefix[i+range] - prefix[i] + prefix[range-1]);
                // debug(range,i,arr[i],val);
                ans = max(ans,sum + val);
            }
        }
        cout<<ans;ce;
        
    }

    return 0;
}
