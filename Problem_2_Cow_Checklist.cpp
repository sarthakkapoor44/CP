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

    {   
        //Lesgooooooo!!!!
        ll h,g;
        cin>>h>>g;
        vp hxy(h+1),gxy(g+1);
        hxy[0]= mp(0,0);
        gxy[0]= mp(0,0);
        forf(i,1,h+1){cin>>hxy[i].fi>>hxy[i].se;} 
        forf(i,1,g+1){cin>>gxy[i].fi>>gxy[i].se;} 
        ll dp[h+1][g+1];
        rep(i,g+1){rep(j,h+1)dp[i][j]=INF;}
        dp[0][0]=0;
        forf(i,0,h+1)
        {
            forf(j,0,g+1)
            {
             if(i || j)  
            { 
                ll  valhh  =pow((hxy[i].fi-hxy[i-1].fi),2)+pow((hxy[i].se-hxy[i-1].se),2);
                ll valgg  = pow((gxy[j-1].fi-gxy[j].fi),2)+pow((gxy[j-1].se-gxy[j].se),2);
                ll valgh = pow((hxy[i-1].fi-gxy[j].fi),2)+pow((gxy[j].se-hxy[i-1].se),2);
                ll valhg  = pow((hxy[i].fi-gxy[j-1].fi),2)+pow((gxy[j-1].se-hxy[i].se),2);
                dp[i][j] = min(min(dp[i-1][j]+valhh,dp[i][j-1]+valgg),min(dp[i-1][j]+valhg,dp[i][j-1]+valgh));
            }
            }
        }
        rep(i,h+1){
            rep(j,g+1)cout<<dp[i][j]<<" ";
            ce;
        }
        cout<<dp[h][g];
    }

    return 0;
}
