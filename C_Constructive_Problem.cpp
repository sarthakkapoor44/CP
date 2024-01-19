///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
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
#define vp vector<pair<ll, ll>>
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 200001;
bool is_prime[MAXN];
int spf[MAXN];

// Function declarations
void sieve();
void sieve_of_eratosthenes();
ll gcd(ll a, ll b);

int main() {
    // Optimize input/output
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    int t=1;
    scanf("%d",&t);
    while (t--)
    {
        ll n;
        scanf("%lld",&n);
        //Lesgooooooo!!!!
        ll cnt[n+1];
        rep(i,n+1){cnt[i]=0;}
        ll arr[n];
         ll large=-1;
        rep(i,n){cin>>arr[i];if(arr[i]<n+1){cnt[arr[i]]++;}}
        // sort(arr,arr+n);
        ll val;
        rep(i,n+1){if(cnt[i]==0){val= i;break;}}
       
        ll minidx=INT_MAX,maxidx=INT_MIN;
        rep(i,n){
            if(arr[i]==val+1){minidx =min(minidx,i);maxidx =max(maxidx,i);}
        }
        // cout<<minidx<<" "<<maxidx;ce;
        if(minidx<n && maxidx>=0){
        forf(i,minidx,maxidx+1){arr[i]=val;}
        }
        else{
           v cnt2(n+1,-1);
           rep(i,n){if(arr[i]>n){arr[i]=val;break;}if(cnt2[arr[i]]!=-1){arr[i]=val;break;}cnt2[arr[i]]++;}
            }
        // rep(i,n){cout<<arr[i]<<" ";};ce;
        rep(i,n+1){cnt[i]=0;}
        rep(i,n){if(arr[i]<n+1){cnt[arr[i]]++;}}
        ll val2;
        rep(i,n+1){if(cnt[i]==0){val2= i;break;}}
        // cout<<val;ce;
        if(val2==val+1){pyes;}else{pno;}ce;

    }

    return 0;
}

void sieve() {
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        spf[i] = i;

    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

ll gcd(ll a, ll b) {
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

void sieve_of_eratosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i <= MAXN; i++) {
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (ll j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
