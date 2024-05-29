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
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
  
    {   //Lesgooooooo!!!!
        ll n,t;
        cin>>n>>t;
        vector<vector<ll > > grid(n,vector<ll>(n,INF));
        rep(i,t)
        {
            ll num;
            cin>>num;
            ll row = (num-1)/n;
            ll col = (num+n-1)%n;
            grid[row][col] = i+1;
        }
        // rep(i,n){rep(j,n)cout<<grid[i][j]<<" ";ce;}
        ll ans =INF;
        rep(i,n)
        {
            ll temp1 =0;
            ll temp2=0;
            rep(j,n)
            {
                temp1 =max(temp1,grid[i][j]);
                temp2 =max(temp2,grid[j][i]);

            }
            ans =  min(ans,min(temp1,temp2));
        }
        ll temp3 =0;
        rep(i,n)
        {
            temp3 =max(temp3,grid[i][i]);
        }
        ans = min(ans,temp3);
        temp3=0;
        rep(i,n)
        {
            temp3= max(temp3,grid[i][n-i-1]);
        }
        ans = min(ans,temp3);
        if(ans==INF)cout<<-1;
        else{cout<<ans;}
    }

    return 0;
}
