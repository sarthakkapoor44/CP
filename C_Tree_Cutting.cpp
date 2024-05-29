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
void calc(ll parent,ll vertex,ll &cnt ,vector<vector<ll> > &adj,v &subtree,ll mid)
{
    subtree[vertex]=1;
    // cout<<vertex<<"->";

    for(auto x:adj[vertex])
    {
        if(x!=parent)
        {
            calc(vertex,x,cnt,adj,subtree,mid);
            subtree[vertex]+=subtree[x];
        }
        
        // cout<<subtree[vertex];ce;
    }
    if(subtree[vertex]>=mid && vertex!=parent){subtree[vertex]=0;cnt++;}

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
        ll n,cuts;
        cin>>n>>cuts;
        vector<vector<ll> >adj(n);
        rep(i,n-1)
        {
            ll a,b;cin>>a>>b;adj[a-1].pb(b-1);adj[b-1].pb(a-1);
        }
        ll left = 1,right  = n/(cuts+1),mid=(left+right)/2;
        ll ans  = 1;
        
      
        while(left<=right)
        {   
            v subtree(n,0);
            mid =  (left+right)/2;
            ll cnt =0;
            calc(0,0,cnt,adj,subtree,mid);
            // cout<<mid<<" "<<cnt;ce;
            // for(auto x:subtree)cout<<x<<" ";ce;
            if(cnt>cuts || (subtree[0]>=mid && cnt==cuts)){ans=max(ans,mid);left=mid+1;}
            else right = mid-1;
        }
        
        cout<<ans;ce;
    }

    return 0;
}
