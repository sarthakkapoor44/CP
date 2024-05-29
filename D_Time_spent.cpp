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
void dfs(ll pos,ll to_reach,vector<vector<ll> > &adj,vp &interval,v &most_time,v &path, v &visited, v &final_path)
{
    cout<<pos;ce;
    
    if(pos==to_reach){visited[pos]=1;final_path = path;return ;}
    if(!visited[pos])
    {
        visited[pos]=1;
        path.pb(pos);
        for(auto x:adj[pos])
        {
            if(!visited[x]) dfs(x,to_reach,adj,interval,most_time,path,visited,final_path);
        }
        path.pop_back();
    }    
    return ;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v most_time(n,-INF);
        vector<vector<ll> > adj(n);
        rep(i,n-1)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        vp interval(n);
        // rep(i,n)
        // {
            v path;v final_path;
            v visited(n,0);
            dfs(0ll,5,adj,interval,most_time,path,visited,final_path);
            cout<<5<<" ";
            for(auto x:final_path )cout<<x<<" ";ce;
        // }
    }

    return 0;
}


// 12   | 17.5 |13.67| 10.5 | 15
// 15.6 | 16.4 |17.4 | 16   | 11.6 
// 18.25| 17.8 |12.5 | 12.86| 8.5
// 15.4 | 16.6 |17   | 15.8 | 13.75
// 6    | 9    |13   | 7.5  | 10