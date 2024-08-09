///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
        ll n;
        cin>>n;
        vll arr(n);
        vll cnt(4);
        rep(i,n){cin>>arr[i];arr[i]%=4;cnt[arr[i]]++;} 
        ll ans  =0;
        ll temp  = min(cnt[1],cnt[3]);
        cnt[1]-=temp;
        cnt[3]-=temp;
        ans+= temp;
        bool flag= 1;
        if(cnt[1]>0)
        {
            if(cnt[1]%2){flag=0;}
            else
            {
                ans+= cnt[1]/2;
                cnt[1]/=2;
                ll val  = cnt[1]+cnt[2];
                if(val%2)flag=0;
                else ans+=val/2;
            }
        }
        else if(cnt[3]>0)
        {
            if(cnt[3]%2){flag=0;}
            else
            {
                ans+= cnt[3]/2;
                cnt[3]/=2;
                ll val  = cnt[3]+cnt[2];
                if(val%2)flag=0;
                else ans+=val/2;
            }
        }
        else {
            if(cnt[2]%2)flag=0;
            else {ans+= cnt[2]/2;}
        }
        if(flag)cout<<ans;
        else cout<<-1;
        ce;
    }

    return 0;
}
