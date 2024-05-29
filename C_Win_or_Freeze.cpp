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
#define pyes cout<<"YES";
#define pno cout<<"NO";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
const ll modn = 998244353;

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
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    

    {   //Lesgooooooo!!!!
        ll n;
        ll n_copy = n;
        cin>>n;
        ll tot = 0;
        ll cnt =0;
        vp primes;
        while(!(n%2)){cnt++;tot++;n/=2;}
       if(cnt) primes.pb(mp(2,cnt));
        // cnt=0;
        for(ll i =3;i*i<=n;i+=2)
        {   cnt = 0;
            while(!(n%i))
            {
                cnt++;tot++;
                n/=i;
            }
            if(cnt)primes.pb(mp(i,cnt));
        }
        
        if(n>1){primes.pb(mp(n,1));tot++;}
        // cout<<tot;ce;ce;
        if(tot==2){cout<<2;}
        else 
        {
            cout<<1;ce;
            if(tot>2){
               if(primes[0].se>=2){cout<<primes[0].fi*primes[0].fi;}
               else cout<<primes[0].fi*primes[1].fi;
                }
            else if(tot<=1)cout<<0;
            ce;
        }
        // rep(i,primes.size()){cout<<primes[i].fi<<"->"<<primes[i].se;ce;}
    }   

    return 0;
}


