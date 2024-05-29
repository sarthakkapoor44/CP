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
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;

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
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,q;
        scanf("%lld %lld",&n,&q);
        ll arr[n];
        rep(i,n)cin(arr[i]);
        v ones(n+1,0);
        v sum(n+1,0);
        ll val =0;
        forf(i,1,n+1)
        {
            if(arr[i-1]==1)
            {
                ones[i]=val+1;val++;
            }
            else
            {
                ones[i]=val;
            }
        }
        val =0;
        forf(i,1,n+1)
        {
            val+=arr[i-1]-1;
            sum[i]=val;
        }
        // rep(i,n+1){cout(ones[i]);}ce;
        // rep(i,n+1){cout(sum[i]);}ce;
        rep(i,q)
        {
            ll a,b;cin(a);cin(b);
            if(sum[b]-sum[a-1]>=ones[b]-ones[a-1] && b!=a){pyes;}
            else{pno;}
            ce;
        }

    }

    return 0;
}
