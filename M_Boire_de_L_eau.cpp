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
#define pyes cout << "YES"
#define pno cout << "NO"
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

ll n, m, k;

ll val = INF;
bool cq(const vector<ll>& arr, ll mx) {
    ll sum = 0;
    ll cnt = 1;
    val = 0 ;
    rep(i, n) {
        if (sum + arr[i] > mx) {
            val = max(val,sum);
            cnt++;
            sum = arr[i];
            if (cnt > m) {
                return false; 
            }
        } else {
            sum += arr[i];
        }
    }
    val = max(val,sum);
    return true;
}

signed main() {
    ll final_val =0;
    cin >> n >> m >> k;
    vll arr(n);
    rep(i, n) cin >> arr[i];

    ll low = *max_element(arr.begin(), arr.end()); 
    ll high = accumulate(arr.begin(), arr.end(), 0ll); 
    ll result = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (cq(arr, mid)) {
            result = mid;
            final_val = val;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    ll ans = (final_val + k - 1) / k;
    cout << ans;
    ce;
    return 0;
}
