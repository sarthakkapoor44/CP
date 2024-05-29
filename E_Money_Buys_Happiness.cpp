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
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll m,x;
        scanf("%lld%lld",&m,&x);
        v cost, hap;  
        ll sum =0;       
        rep(i,m)
        {
            ll c,h;
            scanf("%lld%lld",&c,&h);
            cost.pb(c);
            hap.pb(h);
            sum+=h;
        }
        vector<vector<ll> > dp(m,vector<ll>(sum+1,INF));
        ll ans  = 0;
        if(cost[0]==0){dp[0][hap[0]]=0;ans=hap[0];}
        dp[0][0] = 0;
       
        for(int i=1;i<m;i++)
        {

            ll sal =  i*x;
            for(int H=0;H<=sum;H++)
            {
               if(H-hap[i]>=0)
               { 
                    dp[i][H-hap[i]]= min(dp[i][H-hap[i]],dp[i-1][H-hap[i]]);
                    if(dp[i-1][H-hap[i]]!=INF && cost[i] <= sal-dp[i-1][H-hap[i]])
                    {
                        dp[i][H] = min(dp[i][H],dp[i-1][H-hap[i]]+cost[i]);
                        ans  =max(ans,(ll)H);
                    }
                }
            }
        }
       cout<<ans;ce;
        
    }

    return 0;
}
