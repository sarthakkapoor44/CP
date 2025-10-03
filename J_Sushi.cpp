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
const ll N = 300 + 5;
ll n;
vector<vector<vector<long double>>> dp(N,vector<vector<long double>>(N,vector<long double>(N,-1)));
long double solve(long double one,long double two,long double three)
{
    if(one < 0 or two < 0 or three < 0)
    {
        return 0;
    }
    if(one == 0 and two == 0 and three == 0)
    {
        return 0;
    }
    if(dp[one][two][three] != -1)
    {
        return dp[one][two][three];
    }
    long double total =  one + two + three;
    return dp[one][two][three] = (long double)(solve(one -1, two,three)*(one) + solve(one+1,two-1,three)*(two) + solve(one,two+1,three-1)*(three) + n)/(total);

}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    // cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
  
        cin>>n;
        long double one = 0,two = 0,three =0 ; 
        vll arr(n);
        rep(i,n)
        {
            cin>>arr[i];
            if(arr[i] == 1)
            {
                one++;
            }
            else if(arr[i] == 2)
            {
                two++;
            }
            else if(arr[i]  == 3)
            {
                three++;
            }
        }
        cout<<setprecision(10)<<solve(one,two,three)<<endl;
        
    }

    return 0;
}
