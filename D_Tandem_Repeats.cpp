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
        string s;cin>>s;
        ll min_len = 0;
        ll n =s.length();
        forb(i,n/2,0)
        {
            v cq(n-i,0);
            rep(j,n-i)
            {
                if(s[j]=='?')cq[j]=1;
                else if(j+i<n && s[j+i]=='?')cq[j]=1;
                else if(s[j]==s[j+i])cq[j]=1;

            }
            ll last=0;
            ll val =0;
            // rep(k,cq.size())cout<<cq[k]<<" ";ce;
            rep(k,cq.size())
            {
                if(val==i){min_len=i;break;}
                if(cq[k]==1){val++;}
                else {val=0;}
                
            }
            if(val==i){min_len=i;}
            if(min_len)break;
        }
        cout<<2*min_len;
        ce;
    }

    return 0;
}
