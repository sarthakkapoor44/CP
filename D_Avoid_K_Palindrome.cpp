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
 
const ll MODN = 998244353;
const ll MAXN = 1000001;
 
template <typename T>
void out(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}
bool check_palindrome(const string& s) {
    ll n = s.length();
    for (ll i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

vector<string> palindrome(ll k) {
    vector<string> pat;
    ll total = 1 << k; 
   rep(i,total){
        string s = "";
        for (ll j = 0; j < k; ++j) {
            s += (i & (1 << j)) ? 'B' : 'A';
        }
        if (check_palindrome(s)) pat.pb(s);
    }
    return pat;
}

ll solve(ll n, ll k, const string& s) {
    
}
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)
 

    {	//Lesgooooooo!!!!
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<string> val = palindrome(k);
        vector<map<string, ll>> dp(n + 1);
        dp[0][""] = 1;
        string s2;
        rep(i,n)s2+=s[i];
        rep(i,n) {
            for (const auto& p : dp[i]) {
                string cur = p.first;
                vector<char> opt = (s[i] == '?') ? vector<char>{'A', 'B'} : vector<char>{s[i]};
                for (char ch : opt) {
                    string temp = cur + ch;
                    if (temp.size() > k) temp.erase(0, 1);  
                    if (temp.size() == k && check_palindrome(temp)) continue;
                    dp[i + 1][temp] = (dp[i + 1][temp] + p.second) % MODN;
                }
            }
        }

        ll res = 0;
        for (const auto& p : dp[n]) {
            res = (res + p.second) % MODN;
        }
        cout<<res;ce;
        
    }

    return 0;
}
