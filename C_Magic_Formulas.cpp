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
    
  
    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
        v arr(n);
        rep(i,n)cin(arr[i]);
        v xors(n+1,0);
        xors[0]=0;
        forf(i,1,n+1){xors[i]= xors[i-1]^i;}
        ll val =0;
        // rep(i,n+1)cout<<xors[i]<<" ";
        forf(i,2,n+1)
        {
            ll repeat =  n/i;
            if((repeat%2)){val^=xors[i-1];}
            val^=xors[n%i];
            
        }
        rep(i,n)
        {
            val^=arr[i];
        }
        cout<<val;ce;
    }

    return 0;
}