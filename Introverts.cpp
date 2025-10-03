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
        ll n;
        cin>>n;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        set<pair<ll,pair<ll,ll>>> spaces;
        vector<ll> idxs(n+1);
        rep(i,n)idxs[arr[i]] = i;
        bool cq=1;
        if(n==1){pyes;ce;continue;}
        if(!((idxs[1] == 0 || idxs[1]==n-1) && (idxs[2]==0 || idxs[2]==n-1))){cq=0;}
        else
        {
            spaces.insert({(n-3)/2,{min(idxs[1],idxs[2]),max(idxs[1],idxs[2])}});
        }
        
        set<ll> inserted;
        inserted.insert(idxs[2]);
        inserted.insert(idxs[1]);
        if(cq)
        {
            for (int i = 3; i <= n; i++)
            {
                auto rightIt = inserted.lower_bound(idxs[i]);
                auto leftIt = prev(rightIt);
                ll leftPos = *leftIt;
                ll rightPos = *rightIt;
                ll distance = rightPos - leftPos - 1;
                ll value = (distance - 1) / 2;

                if (!spaces.count({value, {leftPos, rightPos}}))
                {
                    cq = false;
                    break;
                }
                auto largestSpace = *prev(spaces.end());
                if (largestSpace.first != value)
                {
                    cq = false;
                    break;
                }

                pair<ll, pair<ll, ll>> currentSpace = {value, {leftPos, rightPos}};
                ll l = currentSpace.second.first + 1;
                ll r = currentSpace.second.second - 1;
                ll mid = (l + r) / 2;

                spaces.erase(currentSpace);

                if ((l + r) % 2 && idxs[i] == mid + 1)
                {
                    mid++;
                }

                if (idxs[i] != mid)
                {
                    cq = false;
                    break;
                }

                inserted.insert(mid);

                if (currentSpace.second.first + 1 < mid)
                {
                    ll newVal = ((mid - currentSpace.second.first - 1) - 1) / 2;
                    spaces.insert({newVal, {currentSpace.second.first, mid}});
                }

                if (mid + 1 < currentSpace.second.second)
                {
                    ll newVal = ((currentSpace.second.second - mid - 1) - 1) / 2;
                    spaces.insert({newVal, {mid, currentSpace.second.second}});
                }
            }
        }
        if(cq)pyes;
        else pno;
        ce;
            
    }

    return 0;
}
