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

vector<vector<ll> > adj;
// const int N =2*1e5;
vector<ll >dp1,dp2;
// dp1 child 
// dp2 parent 
void dfs(ll pos,ll parent)
{
    dp1[pos]=0;
    for(auto x:adj[pos])
    {   
        if(x==parent)continue;
        dfs(x,pos);
        dp1[pos] =max(dp1[x]+1,dp1[pos]);
    }
    return;
 
}
void dfs2(ll pos,ll parent)
{
    ll mxfi =-INF,mxse=-INF;
    for(auto x:adj[pos])
    {
        if(x==parent)continue;
        if(dp1[x]>mxfi){mxse=mxfi;mxfi=dp1[x];}
        else if(dp1[x]>mxse){mxse = dp1[x];}
    }
    // cout<<pos<<" "<<mxfi<<" "<<mxse;ce;
    for(auto x:adj[pos])
    {
        if(x==parent)continue;
        dp2[x] =dp2[pos]+1;
        if(mxfi!=dp1[x])
        {
            dp2[x] =  max(1+dp2[pos],2+mxfi);
        }
        else if(mxse!=-INF)
        {
            dp2[x] = max(1+dp2[pos],2+mxse);
        }
        dfs2(x,pos);
    }

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
        ll n;
        cin>>n;
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj.clear();
        adj.resize(n);
        rep(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            adj[x-1].pb(y-1);
            adj[y-1].pb(x-1);
        }
  
        dp1.clear();
        dp2.clear();
        dp1.resize(n);
        dp2.resize(n); 
        dfs(a,-1);
        dfs2(a,-1);
        queue<ll> q;
        q.push(a);
        vector<ll>path(n),vis(n,0);
        vis[a]=1;
        bool flag =0;
        while(!q.empty())
        {
            ll num = q.front();
            q.pop();
            for(auto x:adj[num])
            {
                if(!vis[x])
                {
                    vis[x]=  1;
                    path[x]=num;
                    if(x==b){flag=1;break;}
                    q.push(x);
                }
            }
            if(flag)break;
        }
        ll mx_d =0;
        ll tot_dist = -1;
        ll dist =-1;
        for(ll i=b;;i=path[i])
        {   
            tot_dist++;
            if(i==a)break;
        }
        ll ans =INF;
        for(ll i=b;;i=path[i])
        {   
            
            dist++;
            mx_d= max(dp1[i],dp2[i]);
            ans = min(ans,(tot_dist-dist)%2+tot_dist-mx_d+2*(n-1));
            if(i==a)break;
        }
        cout<<ans;ce;
    }

    return 0;
}
