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

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    // gcd_snip //spf_snip // erat_snip
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;cin>>n;
    v arr(n);rep(i,n)cin>>arr[i];
    vector<vector<int> > adj(n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]+i<n)
        {
            adj[arr[i]+i].push_back(i);
        }
        if(-arr[i]+i>=0)
        {
            adj[-arr[i]+i].push_back(i);
        }
    }
    vector<int> dist(n,-1);
    vector<int> vis(n,0);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if((arr[i]%2)){dist[i]=0;vis[i]=1;q.push(i);}
    }
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        for(auto x: adj[num])
        {
            if(!vis[x])
            {
                vis[x]=1;
                dist[x] =dist[num]+1;
                q.push(x);
            }
        }
    }
    vector<int> dist2(n,-1),vis2(n,0);
    for(int i=0;i<n;i++)
    {
        if(!(arr[i]%2)){dist2[i]=0;vis2[i]=1;q.push(i);}
    }
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        for(auto x: adj[num])
        {
            if(!vis2[x])
            {
                vis2[x]=1;
                dist2[x] =dist2[num]+1;
                q.push(x);
            }
        }
    }
    // for(auto x: dist2)cout<<x<<" ";ce;
    for(int i=0;i<n;i++)
    {
        if(!(arr[i]%2))cout<<dist[i]<<" ";
        else cout<<dist2[i]<<" ";
    }
    ce;
    return 0;
}
