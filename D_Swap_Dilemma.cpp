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
     
        ll n;cin >> n;
        vll a(n), b(n);
        rep(i,n)cin>>a[i];
        rep(i,n)cin>>b[i];
        auto cnt = [](vll& array) -> ll {
            function<ll(vll&, ll, ll,ll)> mc = [&](vll& arr, ll left, ll mid, ll right) -> ll {
                ll i = left;ll j = mid + 1;ll k = 0;
                vll temp(right - left + 1);ll inv = 0;
                while (i <= mid && j <= right) { if (arr[i] <= arr[j]) { temp[k++] = arr[i++];} 
                    else { temp[k++] = arr[j++];inv += (mid - i + 1);}}
                while (i <= mid) {temp[k++] = arr[i++];}
                while (j <= right) {temp[k++] = arr[j++];}
                for (i = left, k = 0; i <= right; ++i, ++k) {arr[i] = temp[k];}
                return inv;
            };
            
            function<ll(vll&, ll, ll)> msc = [&](vll& arr, ll left, ll right) -> ll {
                ll inv = 0;
                if (left < right) {
                    ll mid = left + (right - left) / 2;
                    inv += msc(arr, left, mid);
                    inv += msc(arr, mid + 1, right);
                    inv += mc(arr, left, mid, right);
                }
                return inv;
            };

            return msc(array, 0, array.size() - 1);
        };
        ll inva = cnt(a);
        ll invb = cnt(b);
        srt(a);srt(b);
        if (a != b) {
            pno;ce;
            continue;
        }

        if (inva%2==invb%2) {
            pyes;ce;
        } else {
            pno;ce;
        }
    }

    return 0;
}
