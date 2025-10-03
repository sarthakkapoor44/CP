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
#define pyes cout<<"Yes"
#define pno cout<<"No"
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
        ll n,m;
        cin>>n>>m;
        vll a(n),b(m);
        rep(i,n)cin>>a[i];
        rep(i,m)cin>>b[i];
        {
            map<ll,ll> m1,m2;
            rep(i,n)
            {
                m1[a[i]]++;
            }
            rep(i,m)
            {
                m2[b[i]]++;
            }
       
            rep(i,n)
            {
                if(m1[a[i]] && m2[a[i]])
                {
                    ll temp = min(m1[a[i]],m2[a[i]]);
                    m1[a[i]]-=temp;
                    m2[a[i]]-=temp;
                }
            }
    
            vll arr;
            for(auto x:m2)rep(i,x.se)arr.pb(x.fi);
            multiset<ll> ms;
            

            for(auto x:m1)
            {
                if(x.se)
                {
                    rep(p,x.se)ms.insert(x.fi);
                }
            }
            
            unordered_map<ll,ll> inf;
            function<bool(ll)> check = [&](ll val)->bool
            {
                
                if(ms.empty())return 0;
                if(inf[val])return 0;
                if(!val || val < *ms.begin())
                {
                    inf[val] =1;
                    return 0;
                }
                if(ms.find(val)!=ms.end())
                {
                    ms.erase(ms.find(val));
                    return 1;
                }
                ll l = val/2;
                ll r = (val+1)/2;
                if(check(l) && check(r))return 1;
                return 0;

            };
            forb(i,arr.size()-1,0)
            {
                if(ms.size()<=arr.size())break;
                if(check(arr[i]))arr.pop_back();
                else break;
            }
            ll cq=1;

            if(ms.size() || arr.size())cq=0;
            if(cq)pyes;
            else
            {
                pno;
            }

        }
        ce;
        
    }

    return 0;
}

