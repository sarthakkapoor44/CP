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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)

const ll MODN = 1e9 + 7;

v primeFactors(ll n) 
{ 
    v vect;
    ll c = 0;
    while ((n % 2) == 0) 
    { 
        c++;
        n = n/2; 
    } 
    if((c%2)) vect.pb(2);

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        c=0;
        while ((n % i) == 0) 
        { 
            c++;
            n = n/i; 
        } 
        if((c%2)) vect.pb(i);
    } 
    if (n > 2) 
        vect.pb(n);

    return vect;
} 

int main() {
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v arr(n,0);
        ll val=0;
        rep(i,n){cin>>arr[i];if(!arr[i]){val++;}}
        map<vector<ll>,ll> patterns;
        ll squares=0;
        rep(i,n)
        {
            v primes;
            if(arr[i]!=0)
            {
                primes = primeFactors(arr[i]);
                patterns[primes]+=1;
            }
        }
        ll ans =0;
        for(auto y:patterns)
        {
            ans+= (y.se*(y.se-1))/2;
        }
        ans+= (val*(n-val) + (val*(val-1))/2);
        cout<<ans;ce;
    }

    return 0;
}




