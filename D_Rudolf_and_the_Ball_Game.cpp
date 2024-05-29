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
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,m,x;
        cin>>n>>m>>x;
        vp moves;
        rep(i,m){
            ll r;char val;cin>>r>>val;
            if(val=='?')moves.pb(mp(r,-1));
            else if(val=='0')moves.pb(mp(r,0));
            else moves.pb(mp(r,1));
        }
        ll dp[m+1][n];
        rep(i,m+1){
            rep(j,n)dp[i][j]=0;
        }
        dp[0][x-1] =1;
        rep(i,m)
        {
           rep(j,n)
           {
            if(dp[i][j]){
                ll fwd = (j+moves[i].fi)%n;
                ll bwd = (j-moves[i].fi+n)%n;
                if(moves[i].se==-1){
                    dp[i+1][fwd]=1;
                    dp[i+1][bwd]=1;
                }
                else if(moves[i].se==0){
                    dp[i+1][fwd]=1;
                }
                else {
                    dp[i+1][bwd]=1;
                }
            }
           }
           
        }
        ll ans =0;
        v anss;

        // rep(j,m+1){
        //     rep(i,n){cout<<dp[j][i]<<" ";}ce;
        // }

        rep(i,n){
            if(dp[m][i]){ans++;anss.pb(i+1);}
        }
        cout<<ans;ce;
        rep(i,anss.size())cout<<anss[i]<<" ";ce;
    }

    return 0;
}
