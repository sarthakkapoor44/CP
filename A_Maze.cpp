///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;


void dfs(vector<string> &grid,ll row,ll col,ll n,ll m,ll &k,vector<vector<bool> >&visited){
if(visited[row][col]==false && grid[row][col]=='.'){
visited[row][col]=true;
for(int i=-1;i<=1;i+=2){
        if(row+i>=0 && row+i<n){
            dfs(grid,row+i,col,n,m,k,visited);
        }
}
for(int i=-1;i<=1;i+=2){
        if(col+i>=0 && col+i<m){
            dfs(grid,row,col+i,n,m,k,visited);
        }
}
if(k!=0){grid[row][col]='X';k--;}
}
return ;
}
int main() {
    // Optimize input/output
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    
        ll n,m,k;cin>>n>>m>>k;
        vector<string> grid(n," ");
        rep(i,n)
        {
        cin>>grid[i];
        }
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        rep(i,n){
            rep(j,m){
                if(grid[i][j]=='.' && visited[i][j]==false){ dfs(grid,i,j,n,m,k,visited);}
            }
        }
       rep(i,n){rep(j,m){cout<<grid[i][j];}ce;}
    

    return 0;
}

