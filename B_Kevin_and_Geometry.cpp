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
    // ce;
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
        srt(arr);
        map<ll,ll> m;
        ll cq1 =0,cq2=0;
        vll ans(4);
        ll last =-1;
        rep(i,n)
        {
            m[arr[i]]++;
            if(m[arr[i]]>=2 && cq1 && arr[i]!=last)
            {
                cq2=1;
                ans= {last,last,arr[i],arr[i]};
                break;
            }
            if(m[arr[i]] >=2 && !cq1)
            {
                cq1 =1;
                last = arr[i];
            }
            if(m[arr[i]]>=4)
            {
                cq2=1;
                ans = {arr[i],arr[i],arr[i],arr[i]};
                // cout<<"her";
                break;
            }
        }
        if(cq2)out(ans);
        else
        {
            if(!cq1)
            {
                cout<<-1;
            }
            else
            {
                ll cq= 0;
                // cout<<"her";
                vector<ll> arr2;
                m[last]-=2;
                for(auto x:m)
                {
                    if(x.se)
                    {
                       rep(j,x.se) arr2.pb(x.fi);
                    }
                }
                srt(arr2);
                rep(i,arr2.size())
                {

                        auto x = lower_bound(arr2.begin()+i+1,arr2.end(),arr2[i]);
                        if(x== arr2.end())continue;
                        else
                        {
                            if(*x < 2*last + arr2[i])
                            {
                                
                                ans ={last,last,arr2[i],*x};cq=1;break;

                                
                            }
                        }   
                }
                if(cq)out(ans);
                else cout<<-1;
            }
        }
        cout<<endl;
    }

    return 0;
}
