///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
//  using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout << endl
#define all(s) s.begin(), s.end()
#define pyes cout << "YES"
#define pno cout << "NO"
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
#define OPTIMIZE_IO                   \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
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

int main()
{
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;fast_sieve
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    // FOR SEGMENT_TREE - seg_snip
    // FOR LCA - lca_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
        int t = 1;
    cin >> t;
    while (t--)
    { // Lesgooooooo!!!!
        ll n;
        cin >> n;
        string s;
        cin >> s;
        s += '1';
        vector<ll> arr(n + 2);
        for (int i = 1; i <= n + 1; i++)
            arr[i] = i;
        ll start = -1;
        bool cq = 1;
        forf(i, 1, n + 2)
        {
            if (start == -1 and s[i - 1] == '0')
            {
                start = i;
            }
            if (s[i - 1] == '1')
            {
                if (start != -1)
                {
                    ll cnt = i - start;
                    if (cnt <= 1)
                    {
                        cq = 0;
                        break;
                    }
                    // debug(start,i,cnt);
                    for (int j = start; j < i; j++)
                    {
                        arr[j] = j+1;
                        if(j==i-1)arr[j] =start;
                        // if(arr[j]>n)arr[j]=arr[j]%n;
                    }
                }
                start = -1;
            }
        }
        if (cq)
        {
            pyes;
            ce;
            forf(i, 1, n + 1) cout << arr[i] << " ";
        }
        else
            pno;
        ce;
    }

    return 0;
}
