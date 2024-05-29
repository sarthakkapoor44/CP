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
const ll MAXN = 100001;
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);
ll indices[MAXN];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
  
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        ll arr[n+1];
        
        forf(i,1,n+1){cin>>arr[i];}
        arr[0]=-1;
        
        v dp(n+1,1);
        dp[0]=0;
        dp[1]=1;
        ll ans =-INF;
        forf(i,1,n+1)
        {   
            set<ll> facts;
            for(ll j=2;j*j<=arr[i];j++)
            {
                
                if(!(arr[i]%j))
                {
                    if(indices[j] && indices[j]<i)
                    {
                        dp[i] = max(dp[i],dp[indices[j]]+1);
                    }
                    if(indices[arr[i]/j] && indices[arr[i]/j]<i)
                    {
                        dp[i] = max(dp[i],dp[indices[arr[i]/j]]+1);
                    }
                    facts.insert(j);
                    facts.insert(arr[i]/j);
                }
                
            }
            indices[arr[i]]=i;
            if(facts.size())
            {
            for(auto x:facts)
            {
                if(x< MAXN && (dp[i]>dp[indices[x]] || indices[x]==0))indices[x]=i;
            }
            }
            ans  = max(ans,dp[i]);
        }
        cout<<ans;ce;
    }

    return 0;
}
