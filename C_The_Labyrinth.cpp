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

ll n,m;
map<ll,ll> cnt;
void dfs(ll r,ll c,vector<string> &grid, vector<vector<ll> > &connected,ll comp)
{
    if(grid[r][c]!='*' && !connected[r][c])
    {
        connected[r][c]=comp;
        cnt[comp]++;
        if(r+1<n)dfs(r+1,c,grid,connected,comp);
        if(c+1<m)dfs(r,c+1,grid,connected,comp);
        if(r-1>=0)dfs(r-1,c,grid,connected,comp);
        if(c-1>=0)dfs(r,c-1,grid,connected,comp);
    }
    return;
}
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    

    {   //Lesgooooooo!!!!
       
        cin>>n>>m;
        vector<string> grid(n);
        rep(i,n)cin>>grid[i];
        vector<vector<ll> >connected(n,vector<ll>(m,0));
        ll comp=1;
        rep(i,n)rep(j,m)
        {

            if(grid[i][j]=='.' && !connected[i][j]){dfs(i,j,grid,connected,comp);comp++;}
        }
        // rep(i,n){rep(j,m){cout<<connected[i][j]<<" ";}ce;}
        rep(i,n)
        {
            rep(j,m)
            {
                if(grid[i][j]=='.')cout<<'.';
                else{
                    set<ll> unique;
                    if(i+1<n) unique.insert(connected[i+1][j]);
                    if(j+1<m) unique.insert(connected[i][j+1]);
                    if(i-1>=0) unique.insert(connected[i-1][j]);
                    if(j-1>=0) unique.insert(connected[i][j-1]);
                    ll sum =0;
                    for(auto x:unique)(sum+=cnt[x]%10)%=10;
                    cout<<(sum+1)%10;
                }
            }
            ce;
        }
    }

    return 0;
}
