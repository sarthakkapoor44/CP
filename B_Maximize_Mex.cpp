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
        ll n,k;
        cin>>n>>k;
        vll arr(n);

        multiset<ll> ms;
        map<ll,multiset<ll>> map;
        set<ll> st;
        rep(i,n)
        {
            cin>>arr[i];
            map[(arr[i]%k)].insert(arr[i]);
            ms.insert(arr[i]);
        }
        ll ans =n;
        rep(i,n)
        {
            if(!ms.size())break;
            ll mods = i%k;
            if(ms.count(i))
            {
                ms.erase(ms.find(i));
                map[mods].erase(map[mods].find(i));
            }
            else
            {
              
                if(map[mods].size())
                {
                    auto x = map[mods].upper_bound(i);
                    if(x == map[mods].begin()){ans =i;break;}
                    else
                    {
                        x--;
                        ll val = *x;
                        map[mods].erase(x);
                        ms.erase(ms.find(val));
                    }
                }
                else {ans = i;break;}
            }
           
        }
        cout<<ans;ce;
    }

    return 0;
}
