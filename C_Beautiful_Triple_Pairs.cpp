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
        ll n;
        cin>>n;
        v arr(n);
        rep(i,n)cin>>arr[i];
        map<pair<ll,ll> ,ll> m1,m2,m3;
        map<vector<ll>,ll>  m4;
        rep(i,n-2)
        {
            ll a= arr[i];
            ll b= arr[i+1];
            ll c = arr[i+2];
            v temp;
            temp.pb(a);
            temp.pb(b);
            temp.pb(c);
            m1[make_pair(a,b)]+=1;
            m2[make_pair(b,c)]+=1;
            m3[make_pair(c,a)]+=1;
            m4[temp]++;
            
        }
        ll ans = 0;
        for(auto x:m1)
        {
            ans+= ((x.se)*(x.se-1))/2;

        }
        for(auto x:m2)
        {
            ans+= ((x.se)*(x.se-1))/2;
            
        }
        for(auto x:m3)
        {
            ans+= ((x.se)*(x.se-1))/2;
            
        }
         for(auto x:m4)
        {
            ans-= 3*(((x.se)*(x.se-1))/2);
            
        }
        cout<<ans;ce;
    }

    return 0;
}
