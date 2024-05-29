#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, t;
    cin >> s >> t;
    ll n = s.length(), m = t.length();
    vector<vector<ll> > dp(n+1, vector<ll>(m+1, 0));
   
    // DP table calculation
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
// cout<<dp[n][m];
    // Backtracking to find one LCS
    string ans;
    while(n > 0 && m > 0) {
        if(s[n-1] == t[m-1]) {
            ans += s[n-1];
            --n; --m;
        }
        else if(dp[n-1][m] > dp[n][m-1]) --n;
        else --m;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}
