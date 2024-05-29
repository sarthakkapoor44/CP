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
        ll n,m;
        cin>>n>>m;
        ll grid[n][m];
        rep(i,n)rep(j,m)cin>>grid[i][j];
        ll mx[n+1][m+1],mn[n+1][m+1];
        rep(i,n+1)rep(j,m+1){mx[i][j]=-INF;mn[i][j]=INF;}
        mn[1][1]=grid[0][0];
        mx[1][1]=grid[0][0];
        forf(i,1,n+1)forf(j,1,m+1)
        {
            if(i>1 || j>1){mx[i][j] = grid[i-1][j-1]+max(mx[i-1][j],mx[i][j-1]);
            mn[i][j] = grid[i-1][j-1]+min(mn[i-1][j],mn[i][j-1]);
        }}
        if(mn[n][m]<=0 && mx[n][m]>=0 && mn[n][m]%2==0){pyes;}else pno;ce;
    }

    return 0;
}
