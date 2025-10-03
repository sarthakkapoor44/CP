#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2000005; // Adjust based on constraints

ll fact[MAXN];
ll inv_fact[MAXN];

// Fast exponentiation to compute a^b mod mod
ll power_mod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>=1;
    }
    return res;
}

// Precompute factorial and inverse factorial arrays
void precompute_factorials(){
    fact[0] = 1;
    for(int i=1;i<MAXN;i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    // Compute inv_fact[MAXN-1]
    inv_fact[MAXN-1] = power_mod(fact[MAXN-1], MOD-2, MOD);
    // Compute inverse factorials
    for(int i=MAXN-2;i>=0;i--){
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

// Function to compute nCr % MOD
ll nCr(ll n, ll r){
    if(r <0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_factorials();
    int T;
    cin >> T;
    while(T--){
        ll N,K;
        cin >> N >> K;
        ll total_R = N -1;
        ll total_U = N -1;
        // Handle cases where K is invalid
        if(K > 2*N -3 || K <0){
            cout << "0\n";
            continue;
        }
        ll segments = K+1;
        // Edge Case: If segments > total_R + total_U, impossible
        if(segments > total_R + total_U){
            cout << "0\n";
            continue;
        }
        // Function to compute paths starting with a specific direction
        auto compute_paths = [&](bool start_with_R) -> ll {
            ll s_R, s_U;
            if(start_with_R){
                s_R = (segments +1)/2;
                s_U = segments /2;
            }
            else{
                s_U = (segments +1)/2;
                s_R = segments /2;
            }
            if(s_R > total_R || s_U > total_U){
                return 0;
            }
            ll ways_R = nCr(total_R -1, s_R -1);
            ll ways_U = nCr(total_U -1, s_U -1);
            return (ways_R * ways_U) % MOD;
        };
        ll paths_start_R = compute_paths(true);
        ll paths_start_U = compute_paths(false);
        ll total_paths = (paths_start_R + paths_start_U) % MOD;
        cout << total_paths << "\n";
    }
}
