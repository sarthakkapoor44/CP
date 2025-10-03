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

ll findMex(vector<ll> vect){
    srt(vect);
    set<ll> st(vect.begin(),vect.end());
    ll val = 0 ;
    for(auto x: st){
        if(x!= val)return val;
        val ++;
    }
    return val;
}

ll zeroCount(vector<ll>&vect){
    ll cnt =0 ;
    for(auto x: vect){
        if(x==0)cnt++;
    }
    return cnt;
}

ll isPerm(vector<ll>& vect){
    return findMex(vect) == vect.size();
}

vector<ll> modify (vector<ll>&arr){
    map<ll,ll> cnt;
    vector<ll> newArr;
    for(auto x: arr)cnt[x]++;
    ll mex = findMex(arr);
    rep(i,arr.size()){
        if(cnt[arr[i]]==1 and arr[i] < mex)newArr.pb(arr[i]);
        else newArr.pb(mex);
    }
    return newArr;
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
        ll n,k;
        cin>>n>>k; 
        vector<ll> arr(n);
        vector<ll> cnt(n+1);
        rep(i,n){
            cin>>arr[i];
            cnt[arr[i]]++;
        }
        ll ans = 0 ;
        ll mex = findMex(arr);
        if(zeroCount(arr) == 0){
            ans = (1-(k&1))*n;
        } else if(zeroCount(arr) > 1){
            if(k==1){
                vector<ll> arr1 = modify(arr);
                ans = accumulate(all(arr1),0LL);
            } else {
                ans = (k&1)*n;
            }
        } else{
            if(isPerm(arr))ans = (n*(n-1))/2;
            vector<ll> arr1 = modify(arr);
            vector<ll> arr2 = modify(arr1);
            vector<ll> arr3 = modify(arr2);
            vector<ll> arr4 = modify(arr3);
            vector<ll> arr5 = modify(arr4);
            if(isPerm(arr4)){ans = (n*(n-1))/2;}
            else {
                if(k==1)ans = accumulate(all(arr1),0LL);
                else if(k==2) ans = accumulate(all(arr2),0LL);
                else if(k==3) ans = accumulate(all(arr3),0LL);
                else {
                    if(k%2 == 0){
                         ans = accumulate(all(arr4),0LL);
                    } else{
                        ans = accumulate(all(arr5),0LL);
                    }
                }
            }
        }
        cout<<ans;ce;
    }

    return 0;
}
