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
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 2e9 + 14;
const ll MAXN = 1000001;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
ll dp[501][62626];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);

    {   
        //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        v arr(n+1);
        rep(i,n+1)arr[i]=i;
        ll val = (n*(n+1))/4;
        // dp[x][i] = dp[x-wi][i-1]+dp[x][i-1]
        dp[0][0] = 1;
        forf(i,1,n+1)
        {
            rep(j,val+1)
            {   
                (dp[i][j]=dp[i-1][j]%MODN)%=MODN;
                if(j-arr[i]>=0)(dp[i][j] +=dp[i-1][j-arr[i]]%MODN)%=MODN; 
            }
        }
        if((((n*(n+1)/2))%2)){cout(0);}
        else cout<<dp[n][val]/2;

    }

    return 0;
}
