///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
// typedef long long unsigned long long;
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
#define rep(i, n) for (unsigned long long i = 0; i < n; i++)
#define forf(i, a, b) for (unsigned long long i = a; i < b; i++)
#define forb(i, s, e) for (unsigned long long i = s; i >= e; i--)
#define vp vector<pair<unsigned long long, unsigned long long> >
#define v vector<unsigned long long>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const unsigned long long MODN = 998244353;
const unsigned long long MAXN = 1000001;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// unsigned long long gcd(unsigned long long a, unsigned long long b);
unsigned long long dp[200001];

unsigned long long fact(unsigned long long n){
    if(dp[n]!=0){return dp[n];}
    if(n==0){return 1;}
    return dp[n] = (n*fact(n-1))%MODN;
}
int main() {
    // Optimize input/output (remove if only using cin cout)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        unsigned long long n;
        scanf("%lld",&n);
        unsigned long long arr[n];
        rep(i,n){cin>>arr[i];}
        sort(arr,arr+n);
        unsigned long long ans=-1;
        if(arr[n-1]==arr[n-2]){ans= fact(n)%MODN;}
        else{
        unsigned long long j =-1;
        if(arr[0]<=arr[n-1]-2){j=0;}
        while(j>=0 && j<n && arr[j]<=arr[n-1]-2){j++;}
        if(j==-1){j=0;}
        if(j==n-1){ans=0;}
        else if(j>=0){
            unsigned long long sum = 0;
            rep(i,j+1){
                (sum += ((fact(n-1-i)%MODN)*(fact(j)/fact(j-i))%MODN)%MODN)%=MODN;
            }
            ans =(fact(n)-sum)%MODN;
        }
        }      
        cout<<ans;ce;  
    }

    return 0;
}

//-----Smallest prime factor----------//
/*
void sieve() {
for (int i = 1; i < MAXN; i++)
    spf[i] = i;
 for (int i = 2; i <  MAXN; i++) {
if (spf[i] != i)
    continue;
for (int d = 2 * i; d < MAXN; d += i)
spf[d] = min(spf[d], i);
}
}
*/


//-----GCD----------//
/*
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}
*/

//-----Sieve of eratosthenes----------//
/*
void sieve_of_eratosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (unsigned long long i = 2; i <= MAXN; i++) {
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (unsigned long long j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
*/