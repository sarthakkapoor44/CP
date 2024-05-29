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
        ll x,y;
        cin>>x>>y;
        ll ans  =1;
        if(!(y%x))
        {
            y/=x;
            ll copy =y;
            vector<ll> binpow(60,0);
            binpow[0]=1;
            binpow[1]=2;
            forf(i,2,60)
            {
                (binpow[i] = (binpow[i-1]*binpow[i-1])%MODN)%=MODN;
            }
            vector<ll> factors;
            if(!(y%2))
            {
                factors.push_back(2);
                while(!(y%2)){y/=2;}
            }
            for(int i=3;i*i<=y;i+=2)
            {
                if(!(y%i))
                {
                    factors.push_back(i);
                    while(!(y%i)){y/=i;}
                }
            }
            if(y>1) factors.push_back(y);

            ll sub  =0;
            ll temp=1;
            bitset<60> r =copy-1;
            rep(i,60)
            {
                if(r[i])
                {
                    (temp*= binpow[i+1]%MODN)%=MODN;
                }
            }
            temp =  (temp-1+MODN)%MODN;
         
            for(auto p:factors)
            {
                bitset<60> fac =(copy/p)-1;

                ll val=1;
                rep(i,60)
                {   
                    if(fac[i])
                    {
                       
                        (val*= binpow[i+1]%MODN)%=MODN;
                    }
                }
                (sub+= (val-1+MODN)%MODN)%=MODN;
            }
            sub =  (MODN-sub)%MODN;
            ans = (temp%MODN + sub%MODN)%MODN;
            ans =max(1ll,ans);
        }
        else ans=0;
        cout<<ans;
        
    }

    return 0;
}
