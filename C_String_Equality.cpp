///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
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
    // Optimize input/output (remove if only using cin cout)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,k;
        scanf("%lld %lld",&n,&k);
        string a,b;cin>>a>>b;
        map<char,ll> a1,b1;
        rep(i,n){a1[a[i]]++;b1[b[i]]++;}
        auto x = a1.begin();
       for(x;x!=a1.end();x++){
        ll val  =min(x->se,b1[x->fi]);
        x->se -=val ;
        if(b1[x->fi])b1[x->fi]-=val;
       }
      
        ll cq=1;
        x = a1.begin();
        auto y =b1.begin();
         while(x!= a1.end() && y!=b1.end()){
            if(x->se==0){x++;}
            if(y->se==0){y++;}
            if(x==a1.end() || y==b1.end()){break;}
            if(x->se!=0 && y->se!=0)
            {
            if(x->fi<=y->fi && x->se%k==0 && y->se%k==0){
                if(x->se<y->se){y->se-=x->se;x->se=0;x++;}
                else if(x->se>y->se){x->se-=y->se;y->se=0;y++;}
                else{x->se=0;y->se=0;x++;y++;}
            }
            else{cq=0;break;}
            }
         }
    for(auto p:a1){if(p.se!=0){cq=0;break;}}
    if(cq){pyes;}else{pno;}ce;
    //   for(auto y:a1){cout<<y.fi<<"->"<<y.se<<" ";}ce;
        // for(auto z:b1){cout<<z.fi<<"->"<<z.se<<" ";}ce;ce;
    }

    return 0;
}

//-----Smallest prime factor----------//
/*
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
*/


//-----GCD----------//
/*
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
*/

//-----Sieve of eratosthenes----------//
/*
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
*/