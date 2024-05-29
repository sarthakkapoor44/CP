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


int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        char trump;cin>>trump;
        map<char,vector<string> > cards;
        rep(i,2*n){
            string p;cin>>p;
            int num = p[0]-'0';
            char house  = p[1];
            cards[house].pb(p);
        }
        vector<string > left;
      
        vector<string> ans;
       for(auto x:cards){
        if(x.fi!=trump){
            if((x.se.size()%2)){
                left.pb(x.se[x.se.size()-1]);
            }
            srt(x.se);
            ll k=0;
            for(int j=0;j<x.se.size()/2;j++){
                // if(x.se[k+1]<x.se[k]){swap(x.se[k],x.se[k+1]);}
                ans.pb(x.se[k]+" "+x.se[k+1]);
                k+=2;
            }

        }
}
    if(left.size()<=cards[trump].size()){
        srt(cards[trump]);
        rep(i,(cards[trump].size()-left.size())/2)
        {
            ans.pb(cards[trump][i]+" "+cards[trump][i+1]);
            
        }
        ll j =0;
        forf(i,cards[trump].size()-left.size(),cards[trump].size())
        {
            ans.pb(left[j]+" "+cards[trump][i]);
            j++;
        }
        rep(i,ans.size())
        {
            cout<<ans[i];ce;
        }
        
        }
    else{cout<<"IMPOSSIBLE";ce;}
      
  

    
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

