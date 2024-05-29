#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tree<pli, null_type, less<pli>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> arr(n);
        rep(i, n) cin >> arr[i];
        ll sum = 0;
        int idx = 0; // unique identifier for each sum
        ordered_set range;
        range.insert({0, idx++}); // insert initial sum with unique index
        ll ans   = 0;
        rep(i, n) {
            sum += arr[i];
             // insert current sum with unique index
            // To find the last position, use index just greater than any current index
            int pos = range.order_of_key({sum, idx}) - 1; // subtract 1 to convert to 0-based index of last occurrence
            range.insert({sum, idx++});
            ans+=pos;
        }
        cout<<ans<<endl;
    }
    return 0;
}
