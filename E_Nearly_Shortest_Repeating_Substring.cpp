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
int cq(string s,ll x)
{
    string one="",two="";
    rep(i,x)one+=s[i];
    forf(i,x,2*x)two+=s[i];
    // cout<<x<<" "<<one<<" "<<two;ce;
    ll j=x;
    ll cnt_one =0,cnt_two=0;
    // cout<<x<<" ";
    for(ll j=x;j<=s.length();j+=x)
    {
        forf(i,j-x,j){
        // cout<<s[i]<<" ";
        if(s[i]!=one[i-j+x])cnt_one++;
        if(s[i]!=two[i-j+x])cnt_two++;
        }
    }
    // cout<<one<<" "<<two;
    // ce;

    if(cnt_one<=1 || cnt_two<=1){return 1;}
    else return 0;
}
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
        string s;cin>>s;
        set<ll> factors;
        for(ll i=2;i*i<=n;i++)
        {
            if(!(n%i)){factors.insert(i);factors.insert(n/i);}
        }
        factors.insert(1);
        ll ans = n;
        for(auto x:factors)
        {
            if(cq(s,x)){ans =x;break;}
        }
        cout<<ans;ce;
    }

    return 0;
}
