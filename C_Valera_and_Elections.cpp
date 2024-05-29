///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi second
#define se first
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

ll n;
void calc(ll parent, ll vertex, vector<vector<ll > > &adj,v &dp)
{
    for(auto x:adj[vertex])
    {
        if(x!=parent)
        {
            calc(vertex,x,adj,dp);
            dp[vertex] +=dp[x];
        }
    }
    return;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
        cin>>n;
        v dp(n,0);
        vector<vector<ll > > adj(n);
        rep(i,n-1)
        {
            ll a,b,w;cin>>a>>b>>w;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
            if(w==2)
            {
                dp[a-1]=1;
                dp[b-1]=1;
            }
        }
        
        calc(-1,0,adj,dp);
        v ans;
        rep(i,n)if(dp[i]==1)ans.pb(i+1);
        cout<<ans.size();ce;
        for(auto x:ans)cout<<x<<" ";ce;
    

    return 0;
}
