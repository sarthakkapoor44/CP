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
        v arr(n,0);
        ll cq=1;
        map<ll,ll> cnt;
        rep(i,n){cin>>arr[i];cnt[arr[i]]++;}
        for(auto x:cnt){if(x.se%2!=0){cq=0;break;}}
       rep(i,n*n){arr.pb(-1);}
       v size;vp moves;
        ll sum =0;
        if(cq){
            ll idx1=0,idx2;
            while(arr[0]!=-1){
            forf(i,idx1+1,arr.size()){if(arr[i]==arr[idx1]){idx2=i;break;}}
            stack<pair<ll,ll> > compare;
            ll len = idx2-idx1;
            forb(i,idx2+len-1,idx2+1){
                compare.push(mp(arr[i],0));
            }
           ll cnt=sum;
        forf(i,idx1+1,idx2){
            if(arr[i]==compare.top().fi){compare.pop();}
            else{moves.pb(mp(cnt+idx2+i,arr[i]));compare.push(mp(arr[i],1));}
           
        }
        vector<ll> temp;
       
        while(!compare.empty()){
            temp.pb(compare.top().fi);compare.pop();
        }
        size.pb(2*len);
        
        forf(i,idx2+len,arr.size()){temp.pb(arr[i]);}
        arr.clear();
        rep(i,temp.size()){
            arr.pb(temp[i]);
        }
         sum+=2*len;
            }
        cout<<moves.size();ce;
        rep(i,moves.size()){cout<<moves[i].fi<<" "<<moves[i].se;ce;}
        cout<<size.size();ce;
        rep(i,size.size())cout<<size[i]<<" ";
        
        }
        else{cout<<-1;}
     ce;
        ce;
        
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