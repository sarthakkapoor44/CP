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
const long long N = 4*1e5+1;
long long binpow[N];
long long binexp[41];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    binpow[0]=1;
    forf(i,1,N){binpow[i]= (2*binpow[i-1]%MODN)%MODN;}
    binexp[0]=1;
    binexp[1]=2;
    forf(i,2,41)
    {
        binexp[i] = ((binexp[i-1]%MODN)*(binexp[i-1]%MODN))%MODN;
    }
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,k;
        cin>>n>>k;
        vector<ll> dp(k+1,0); 
        dp[0]=1;
        ll pow1 = (binpow[n-1]+MODN-1)%MODN; // 2^n-1 -1
        ll pow2 = (binpow[n-1]+1)%MODN; //2^n-1 +1
        if((n%2))
        {
            forf(i,1,k+1)
            {
               ( dp[i] = (dp[i-1]*pow2)%MODN)%=MODN;
            }
        }
        else
        {
            forf(i,1,k+1)
            {
                bitset<40> x = n*(i-1);
                ll pow3=1;
                rep(j,41)
                {
                   if(x[j]){(pow3*= binexp[j+1]%MODN)%=MODN;} 
                 
                }
                // cout<<pow3;ce;
                dp[i] = ((dp[i-1]*pow1)%MODN+ pow3%MODN)%MODN;
            }
        }
        cout<<dp[k]%MODN<<" ";ce;
    }

    return 0;
}
