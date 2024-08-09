///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce cout << endl
#define all(s) s.begin(), s.end()
#define pyes cout << "YES";
#define pno cout << "NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define vll vector<ll>
#define OPTIMIZE_IO std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);

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
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vll arr(n);
        vll vect2;
        rep(i, n)
        {
            cin >> arr[i];
        }
        ll ans = 0;
        vector<ll> pre(n, 0),pre_last(n);
        vll last(n, 0); // Properly initialize last with 0
        rep(i, n)
        {
            pre[i] = (i ? pre[i - 1] : 0) + arr[i];
            if (arr[i] > x)
            {
                last[i] = i + 1;
              
            }
            else
            {
                if (pre[i] <= x)
                {
                    ans += i + 1;
                }
                else
                {
                    auto y = lower_bound(pre.begin(), pre.begin() + i + 1, pre[i] - x);
                    
                    ll idx = y - pre.begin();
                    cout<<i<<" "<<idx;ce;
                    last[i] = idx + 1;
                    
                    if (i - idx >= 0)
                        ans += i - idx;
                    if (i) ans += pre_last[i-1] - (pre_last[idx]);
                    
                    
                }
            }
            pre_last[i] = (i?pre_last[i-1]:0) + last[i];
        }
        for(int i=0;i<n;i++)cout<<pre_last[i]<<" ";
        ce;
        cout << ans;
        ce;
    }

    return 0;
}
