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
        ll s = 0 ;
        rep(i,n){
         s+= (i%2==0)*arr[i] + (i%2==1)*(-arr[i]);   
        }
        ll max_ans = s;
        set<ll> st;
        for(int i  = 0; i < n ;i++){
            if(i%2==0){
                max_ans =max(max_ans,s+i+1-1);
                st.insert(2*arr[i]+i+1);
            } else {
                max_ans =max(max_ans,s+i+1-2);
                max_ans = max(max_ans,s+ 2*arr[i]+i+1 -*(st.begin() ));
            }
        }

        for(int i  = n-1; i >=0  ;i--){
            if(i%2==0){
                // max_ans =max(max_ans,s+i+1-1);
                st.insert(2*arr[i]-i-1);
            } else {
                // max_ans =max(max_ans,s+i+1-2);
                max_ans = max(max_ans,s+ 2*arr[i]-i-1 -*(st.begin() ));
            }
        }

        cout<<max_ans;ce;
        
    }

    return 0;
}
