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

void dfs(ll pos,vector<vector<int> >  &adj,int &cq,v &visited, v &topo)
{   
    if(visited[pos]==2)return;
    if(visited[pos]==1){cq=0;return;}
    if(visited[pos]==0)
    {
        
        visited[pos]=1;
        
        if(adj[pos].size())
        {
            rep(i,adj[pos].size())
            {
                ll x= adj[pos][i];
                dfs(x,adj,cq,visited,topo);
            }
        }
        
    }
    topo.pb(pos);
    visited[pos]=2;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

     //Lesgooooooo!!!!
    ll n;
    cin>>n;
    vector<vector<int> >adj(26); 
    string prev;cin>>prev;
    int cq =1;
    rep(j,n-1)
    {
       string curr;
       cin>>curr;
       int diff=0;
       rep(i,min(curr.length(),prev.length()))
       {
            if(curr[i]!=prev[i])
            {
                diff= 1;
                adj[prev[i]-'a'].pb(curr[i]-'a');
                break;
            }
        }
        if(!diff && curr.length()<prev.length())cq=0;
        prev = curr;
    }
    v visited(26,0);
    v topo;
    rep(i,26)
    {
        if(adj[i].size() && !visited[i])dfs(i,adj,cq,visited,topo);
        if(!cq)break;
    }
    if(!cq){cout<<"Impossible";}
    else
    {   v arr(26,1);
    reverse(all(topo));
        for(auto x:topo){cout<<char(x+'a');arr[x]=0;}
        rep(i,26)if(arr[i])cout<<char(i+'a');
    }
    ce;
  
    return 0;
}
