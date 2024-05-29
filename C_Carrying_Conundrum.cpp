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
    // Optimize input/output (remove if only using cin cout)
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
    
        ll n;
        
        scanf("%lld",&n);
        //  if(t==891){cout<<n<<" ";}
        string num = to_string(n);
        ll len = num.length();
        reverse(all(num));
        ll ans =0;
        if(len-2>0)
        {
        
        rep(i,pow(2,len-2))
        {
            vector<int> arr(2,0);
            ll val  =i;
            ll temp=1;
            rep(k,len-2){arr.pb(val%2);val/=2;}
            // for (auto x: arr){cout<<x<<" ";}ce;
            rep(j,len){
                ll conv = num[j]-'0';
                ll curr = (conv-arr[j]);
                // cout<<curr<<"-";ce;
                if(curr==9 && j+2<len && arr[j+2]){if(!arr[j]){temp=0;}}
                if(curr<0 && j+2<len && arr[j+2]){curr = (curr+10)%10;}
                else if(curr<0){temp=0;}

                if(j+2<len){
                    if(arr[j+2]){
                        if(curr==9){temp*=10;}
                        else{temp *=(9-curr);}
                    }
                    else{temp *=(curr+1);}
                }
                else{temp*= (curr+1);}
            }
        // cout<<temp<<"-";ce;
        ans+=temp;
        } 
        }
        else {
            ans = num[0]-'0'+1;
            if(len==2)ans = (num[0]-'0'+1)*(num[1]-'0'+1);
          
        }
        cout<<ans-2;ce;

        
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