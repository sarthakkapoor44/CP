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
 
    // int t=1;
    // cin>>t;
    // while (t--)
    {	//Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        vll arr(n);
        rep(i,n)cin>>arr[i];
        vector<ll> prev(m+1,-INF),curr(m+1,-INF),temp(m+2,0);
        prev[0] = 0;
        curr[0] = 0;
        ll tot_points= 0 ;
        function<void(ll,ll)> add = [&](ll s,ll e)->void{
            if(s>e)return ;
            temp[s]+=1;
            temp[e+1]-=1;
        };
        function<void(vector<ll>& )> update = [&](vector<ll> &dp)->void{
            ll sum = 0 ;
            rep(i,temp.size())
            {
                sum+= temp[i];
                temp[i] = 0;
                if(i<dp.size() && dp[i]>-INF)dp[i]+=sum;
            }
        };
        rep(i,n)
        {
            if(arr[i]==0)
            {
                update(prev);
                for(int j =m;j>=1;j--)
                {
                    curr[j] =max((j+1<=m?curr[j+1]:0),max(prev[j],prev[j-1]));
                }
                tot_points++;
                prev = curr;
            }
            else if(arr[i]>0)
            {
                add(arr[i],m);
            }
            else{
                add(0,tot_points+arr[i]);
            }
          
        }
        update(prev);
        for(int j =m;j>=1;j--)
        {
            curr[j] =max((j+1<=m?curr[j+1]:0),max(prev[j],prev[j-1]));
        }
        ll val  = *max_element(all(curr));
        if(val==-INF)val=0;
        cout<<val;ce;
    }

    return 0;
}
