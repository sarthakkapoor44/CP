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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 
    int t=1;
    cin>>t;
    while (t--)
    {	//Lesgooooooo!!!!
        ll n,q;
        cin>>n>>q;
        vector<ll> arr(n);
        rep(i,n)cin>>arr[i];
        ll sum = accumulate(all(arr),0ll);
        vector<ll> pre(n),suf(n);
        for(int i=0;i<n;i++)
        {
            pre[i] = arr[i]+ (i?pre[i-1]:0);
        }
        for(int i=n-1;i>=0;i--)
        {
            suf[i] = ((i+1<n)?suf[i+1]:0) + arr[i];
        }
        
        rep(i,q)
        {
            ll l,r;cin>>l>>r;
            l--;r--;
            ll ltimes = l/n;
            ll loff = l%n;
            ll rtimes = r/n;
            ll roff = r%n;
            ll ans = (max(0ll,rtimes-ltimes-1))*sum;

            ll lidx = (loff + ltimes)%n;
            ll ridx = (roff + rtimes)%n;
            if(ltimes!=rtimes)
            {   
                if(lidx<loff)
                {
                    ans += (ltimes?pre[ltimes-1]:0) - (lidx?pre[lidx-1]:0);
                }
                else
                {
                    ans += (ltimes?pre[ltimes-1]:0) + suf[lidx];
                }

                if(ridx <roff)
                {
                    ans += pre[ridx] + suf[n-(roff-ridx)];
                }
                else{
                    ans += pre[ridx] - (rtimes?pre[rtimes-1]:0);
                }

            }
            else 
            {
                if(lidx<loff)
                {
                    ans += pre[ridx] - (lidx?pre[lidx-1]:0);
                }
                else
                {
                    if(ridx<roff){
                        ans+= suf[lidx]+ pre[ridx];
                    }
                    else
                    {
                        ans+= suf[lidx] - (ridx+1<n?suf[ridx+1]:0); 
                    }
                }
            }
            cout<<ans;ce;
        }
    }

    return 0;
}
