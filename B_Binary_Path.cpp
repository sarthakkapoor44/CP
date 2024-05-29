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
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        vector<string> grid(2);
        cin>> grid[0]>>grid[1];
        v temp;
        temp.pb(grid[0][0]-'0');
        // ll cnt= 0;
        ll idx =n;
        forf(i,1,n)
        {   
           if((grid[0][i]-'0')>(grid[1][i-1]-'0')){temp.pb(grid[1][i-1]-'0');idx=i;break;}
           else{temp.pb(grid[0][i]-'0');}
            
        }
        // cout<<idx;ce;
       forf(i,idx,n-1){temp.pb(grid[1][i]-'0');}
       ll cnt=1;
 
       forb(i,idx-1,1)
       {
        // cout<<grid[0][i]<<" "<<grid[1][i-1];ce;
        if((grid[0][i]-'0')!=(grid[1][i-1]-'0')){break;}
        else {cnt++;}
       }

       temp.pb(grid[1][n-1]-'0');
       for(auto x:temp)cout<<x;
       ce;
       cout<<cnt;ce;
    // ce;
    }

    return 0;
}
