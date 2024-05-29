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
        ll n,m;
        cin>>n>>m;
        string s;cin>>s;
        vector<vector<int> > adj(n),adjt(n);
        vector<int> in_deg(n,0);
        rep(i,m)
        {
            int a,b;cin>>a>>b;
            in_deg[b-1]++;
            adj[a-1].pb(b-1);
            adjt[b-1].pb(a-1);
        }
        queue<int> q;
        vector<int> topo;
        rep(i,n){if(in_deg[i]==0){q.push(i);topo.pb(i);}}
        
        while(!q.empty())
        {
            int curr  = q.front();
            q.pop();
            for(auto x:adj[curr])
            {
                in_deg[x]--;
                if(in_deg[x]==0){q.push(x);topo.pb(x);}
            }
        }
        // for(auto x:topo)cout<<x<<" ";ce;
        int ans=-1;
        
        if(topo.size()==n)
        {
            vector<vector<int> > dp(n,vector<int>(26,0));
            rep(i,n)
            {
                int node = topo[i];
                int letter = s[node]-'a';
                dp[node][letter]=1;
                rep(i,26)
                {
                    for(auto x:adjt[node])
                    {
                       if(i==letter) dp[node][letter]= max(1+dp[x][letter],dp[node][letter]);
                       else dp[node][i] = max(dp[node][i],dp[x][i]);
                    }
                }
                ans = max(ans,dp[node][letter]);
            }

        }
        cout<<ans;ce;
    }

    return 0;
}
