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

set<int>* segment;
 

void build(int i, int s, int e, v arr)
{
    if (s == e) {
        segment[i].insert(arr[s]);
        return;
    }
 
    build(2 * i, s, (s + e) / 2, arr);
    build(1 + 2 * i, 1 + (s + e) / 2, e, arr);

    segment[i].insert(segment[2 * i].begin(),
                      segment[2 * i].end());
 
    segment[i].insert(segment[2 * i + 1].begin(),
                      segment[2 * i + 1].end());
}
 

set<int> query(int node, int l, int r, int a, int b)
{
    set<int> left, right, result;

    if (b < l || a > r)
        return result;
 
    if (a <= l && r <= b)
        return segment[node];
 
    left = query(2 * node, l, (l + r) / 2, a, b);
    result.insert(left.begin(), left.end());
 
    right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b);
    result.insert(right.begin(), right.end());
 
 
    return result;
}
 
void init(int n)
{
    int h = (int)ceil(log2(n));
    h = (2 * (pow(2, h))) - 1;
 
    segment = new set<int>[h];
}
 

void getDistinct(int l, int r, int n)
{
    set<int> ans = query(1, 0, n - 1, l, r);
 
    cout << ans.size() <<" ";
}

void dfs(ll pos,vector<vector<ll> > &adj,v &col, v &euler,ll parent,vp &times,int &time)
{
    euler.pb(col[pos]);
    time++;
    times[pos].fi=time;
    for(auto x:adj[pos] )
    {
        if(x!=parent)
        {
            dfs(x,adj,col,euler,pos,times,time);
        }
    }
    time++;
    euler.pb(col[pos]);
    times[pos].se= time;
    return ;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
   
    {   //Lesgooooooo!!!!
        ll n;
        cin>>n;
        v col(n);rep(i,n)cin>>col[i];
        vector<vector<ll> > adj(n);
        rep(i,n-1)
        {
            ll a,b;cin>>a>>b;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        v euler;
      
        int time =0;
        vp times(n,mp(0,0));
        dfs(0,adj,col,euler,-1,times,time);
        n = euler.size();
        rep(i,n)cout<<euler[i]<<" ";ce;
        init(n);
        build(1, 0, n - 1, euler);
        for(auto x:times)
        {
            getDistinct(x.fi-1, x.se-1, n);
        }
    }

    return 0;
}
