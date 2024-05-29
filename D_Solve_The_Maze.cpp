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
#define pyes cout<<"Yes";
#define pno cout<<"No";
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
void dfs(ll r,ll c,  vector< vector<char> > &grid, vector<vector<bool>  > &visited,ll &indicator)
{
    if(!visited[r][c] && grid[r][c]!='#')
    {
    visited[r][c]=true;
    if(grid[r][c]=='G')indicator++;
    else if(grid[r][c]=='B'){indicator=-INF;return;}
    if(r+1<n)dfs(r+1,c,grid,visited,indicator);
    if(c+1<m)dfs(r,c+1,grid,visited,indicator);
    if(r-1>=0)dfs(r-1,c,grid,visited,indicator);
    if(c-1>=0)dfs(r,c-1,grid,visited,indicator);
    }
    return ;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        ll t;cin>>t;while(t--){
       //Lesgooooooo!!!!
        cin>>n>>m;
        vector< vector<char> > grid(n,vector<char>(m));
         vp indices_b;
        ll good =0;
        rep(i,n)rep(j,m)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='G' ){good++;}
            if(grid[i][j]=='B')indices_b.pb(mp(i,j));
        }
   
       
        for(auto y:indices_b)
        {
            ll i = y.fi;
            ll j = y.se;
            if(grid[i][j]=='B')
            {
                if(i+1<n && grid[i+1][j]=='.')grid[i+1][j]='#';
                if(j+1<m && grid[i][j+1]=='.')grid[i][j+1]='#';
                if(i-1>=0 && grid[i-1][j]=='.')grid[i-1][j]='#';
                if(j-1>=0 && grid[i][j-1]=='.')grid[i][j-1]='#';
            }
        }
        ll cq=1;
        vector<vector<bool>  > visited(n,vector<bool>(m,false));
        ll gd_count=0;
        if(grid[n-1][m-1]=='.')
        {
            dfs(n-1,m-1,grid,visited,gd_count);
            if(gd_count==-INF)cq=0;
        }
       if(gd_count!=good)cq=0;
    if(cq){pyes;}
    else{pno;}ce;
        }
    return 0;
}
