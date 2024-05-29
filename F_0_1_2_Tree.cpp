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
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll a,b,c;cin>>a>>b>>c;
        ll n  = a+b+c;
        ll power=0;
        if(a)
        {
        forf(i,0,21)
        {
            if(a>((1<<i)-1) && a<=(1<<(i+1))-1){power=i;break;}
        }

        ll lvs1  =  2*a+1 - ((1<<(power+1))-1) ;
        ll lvs2  = (1<<(power))-(lvs1/2);
        ll ht = power+1;
       
        ht += b/(lvs1+lvs2);
        if(b%(lvs1+lvs2)>lvs2)ht++;

        if((lvs1+lvs2)==c)cout<<ht;
        else{cout<<-1;}
        
        }
        else
        {
            if(c>1)cout<<-1;
            else if(a==0 && c==0 )cout<<-1;
            else cout<<(b);
        }
        ce;
        
    }

    return 0;
}
