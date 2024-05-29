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
        int n =s.length();
        int prefix[n+1];
        prefix[0]=0;
        rep(i,n)
        {
            if(s[i]=='1')prefix[i+1]=(prefix[i]-1);
            else prefix[i+1]=(prefix[i]+1);
        }
        rep(i,n+1)cout<<prefix[i]<<" ";ce;
        ll ans =-INF;
        ll post_max=0;
        ll sum =0;
        ll left =-1,right=n;
        forb(i,n,0)
        {   
          
            if(i!=n){
            if(s[i]=='1')sum=sum-1;
            else sum=sum+1;
            }
            if(post_max<sum)
            {
                post_max =sum;
                right =i;
            }
            if(ans<prefix[i]+post_max)
            {
                ans =prefix[i]+post_max;
                left =i;
            }
            ans = max(prefix[i]+post_max,ans);
        }
         cout<<left<<" "<<right;ce;
    }
   
    return 0;
}
