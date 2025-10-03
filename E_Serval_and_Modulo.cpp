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
ll cnt[MAXN];
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    // OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    scanf("%d",&t);
    while (t--)
    {	//Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll sum1 =0 ,sum2= 0;
        long long arr1[n],arr2[n];
        rep(i,n){scanf("%lld",&arr1[i]);sum1+=arr1[i];}
        rep(i,n){scanf("%lld",&arr2[i]);sum2+=arr2[i];}
        ll diff = sum1-sum2;
     
     
        // rep(i,n)cnt[arr2[i]]++;
       
        if(diff==0)
        {

            // unordered_map<ll,ll> m2;
            ll num =1e9;
            rep(i,n)cnt[(arr1[i])]++;
            bool flag = true;
            rep(i,n)
            {
                cnt[arr2[i]]--;
                if(cnt[arr2[i]]<0)
                {
                    cnt[arr2[i]]=0;
                    rep(j,n)cnt[arr1[j]]=0;
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cout<<num;ce;
                continue;
            }
        }
        
        ll ans =-1;
        // factors.insert(1e9);
        for(ll  i= 1;i*i<=diff;i++)
        {
            ll num = i;
            if((diff%num)!=0)continue;
            rep(i,n)cnt[(arr1[i])%num]++;
            bool flag = true;
            rep(j,n)
            {
                cnt[arr2[j]]--;
                if(cnt[arr2[j]]<0)
                {
                    cnt[arr2[j]]=0;
                    rep(k,n)cnt[arr1[k]%num]=0;
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans = num;
                continue;
            }

             num= diff/i;
             rep(i,n)cnt[(arr1[i])%num]++;
              flag = true;
             rep(j,n)
             {
                 cnt[arr2[j]]--;
                 if(cnt[arr2[j]]<0)
                 {
                     cnt[arr2[j]]=0;
                     rep(k,n)cnt[arr1[k]%num]=0;
                     flag = false;
                     break;
                 }
             }
             if(flag)
             {
                 ans = num;
                 continue;
             }
 
        }

        cout<<ans;ce;
    }

    return 0;
}
