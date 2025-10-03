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
#define pyes cout<<"YES";
#define pno cout<<"NO";
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
 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        vector<string> portals(n);
        vector<ll> arr(n);
        map<char,ll> convert;
        convert['B'] = 8;
        convert['G'] = 4;
        convert['Y'] = 2;
        convert['R'] = 1;
        map<ll,vector<ll>> nums;

        rep(i,n)
        {
            cin>>portals[i];
            ll val =  convert[portals[i][0]] +  convert[portals[i][1]];
            arr[i]  = val;
            nums[val].pb(i);
           
        }
        rep(i,q)
        {
            ll ans= INF;
            ll a,b;
            cin>>a>>b;
            a--;b--;
            if((arr[a]&arr[b]))
            {
                ans = abs(b-a);
            }
            else
            {
                if(a>b)swap(a,b);
                for(int j=0;j<1<<4;j++)
                {
                    if(__builtin_popcount(j)==2 && j!=arr[a] && j!=arr[b] && (j&arr[a]) && (j&arr[b]))
                    {
                        // out(nums[j]);
                        auto x = lower_bound(nums[j].begin(),nums[j].end(),b) ;
                        if(x!=nums[j].end())
                        {
                            ans = min(ans,abs(*x-b) + abs(*x-a));
                        }
                        if(x!=nums[j].begin())
                        {
                            x--;
                            ans = min(ans,abs(*x-b) + abs(*x-a));
                        }
                    }
                }
            }
            if(ans==INF)ans=-1;
            cout<<ans;ce;
        }
        
    }

    return 0;
}
