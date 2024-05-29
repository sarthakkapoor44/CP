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
const ll MAXN = 10000001;


int spf[MAXN]; 
void sieve();


vector<int> get_primes(ll val){
    vector<int> primes;
    while(val!=1){
        primes.pb(spf[val]);
        val = val/spf[val];
    }
    return primes;
}
int main() {
    sieve();
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        int a,b;
        scanf("%d %d",&a,&b);
        int diff = b-a;
        ll ans=INF;
        if(diff==1){ans=-1;}
        else{
        vector<int> primes;
        if(diff<MAXN) primes = get_primes(diff);
        if(primes.size()>0) for (auto p:primes){ans = min(ans,ll((p-a%p)%p));}
        } 
        if(ans==INF) ans=0;
        printf("%lld",ans);ce;
    }

    return 0;
}

//-----Smallest prime factor----------//

void sieve()
{
    for (int i = 1; i < MAXN; i++){spf[i] = i;}
    for (int i = 2; i <  MAXN; i++) 
    {
        if (spf[i] != i){continue;}
        for (ll d = 2 * i; d < MAXN; d += i)
            spf[d] = min(spf[d], i);
    }
return ;
}



