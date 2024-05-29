///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n)cin>>arr[i];
        ll dp[513];
        rep(i,513){dp[i]=INF;}
        dp[0]=0;
        ll cnt =0;
        rep(i,n)
        {
            rep(x,513)
            {
                
                if(dp[x]!=INF && arr[i]>dp[x])
                {
                    if(dp[(x^(arr[i]))]==INF)cnt++;
                    dp[(x^arr[i])] = min(dp[(x^arr[i])],arr[i]);

                }
            }
     
        }
        cout<<cnt+1;ce;
        rep(i,513){if(dp[i]!=INF)cout<<i<<" ";}ce;
        // cout<<vals.size();ce;
        // for(auto x:vals)cout<<x<<" ";ce;

    }

    return 0;
}
