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
ll n,m;
void dfs(ll r,ll c, vector<string> &grid, vector<vector<bool>  > &visited)
{
    if(!visited[r][c] && grid[r][c]=='.'){
    visited[r][c]=true;
    if(r+1<n)dfs(r+1,c,grid,visited);
    if(c+1<m)dfs(r,c+1,grid,visited);
    if(r-1>=0)dfs(r-1,c,grid,visited);
    if(c-1>=0)dfs(r,c-1,grid,visited);
    }
    return ;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

       //Lesgooooooo!!!!
        cin>>n>>m;
        vector<string> grid(n);
        rep(i,n)cin>>grid[i];
        vector<vector<bool>  > visited(n,vector<bool>(m,false));
        ll rooms =0;
        rep(i,n)rep(j,m)if(!visited[i][j] && grid[i][j]=='.'){dfs(i,j,grid,visited);rooms++;}
    
    cout<<rooms;ce;
    return 0;
}
