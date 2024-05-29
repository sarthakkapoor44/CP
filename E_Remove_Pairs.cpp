/////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
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
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
class Solution {
private:
   v A,B;
    ll N;
    unordered_map<ll, bool> dp;

    bool check(ll state) {
        // If the state has been calculated before, return the result
        if (dp.find(state) != dp.end()) {
            return dp[state];
        }
        bool win = false;
        rep(i,N) {
        if (!(state & (1 << i))) continue;
        for (ll j = i + 1; j < N; ++j) {
        if (!(state & (1 << j))) continue;
        if (A[i] == A[j] || B[i] == B[j]) {
        // Move and remove cards i and j
        ll next_state = state & ~(1 << i) & ~(1 << j);
        // If opponent cannot win from next state, current player can win
        if (!check(next_state)) {
            win = true;
            break;
        }
        }
        }
            if (win) break;
        }

        // Memorize and return the result
        dp[state] = win;
        return win;
    }

public:
    Solution(const v& A, const v& B) : A(A), B(B) {
        N = A.size();
    }

    string whoWins() {
        ll initial_state = (1 << N) - 1;
        return check(initial_state) ? "Takahashi" : "Aoki";
    }
};
void solve()
{
    ll n;
    cin>>n;
    v A(n),B(n);
    rep(i,n)cin>>A[i]>>B[i];

    Solution game(A, B);
    cout << game.whoWins() << endl; 
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    {   //Lesgooooooo!!!!
    solve();        
    }

    return 0;
}
