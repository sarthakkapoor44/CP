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
bool cycle(int pos,vector<vector<int> > &adj,vector<int> &topo,vector<int> &visited)
{
    visited[pos]=1;
    for(auto x: adj[pos])
    {
        if(visited[x]==1)return true;
        if(!visited[x]){if(cycle(x,adj,topo,visited))return true;}
    }
    visited[pos]=2;
    topo.push_back(pos);
    return false;
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
        ll n,m;
        cin>>n>>m;
        vector<vector<int> >adj(n);
        vector<pair<int,int> > edge_list;
        for(int i=0;i<m;i++)
        {
            int type,a,b;
            cin>>type>>a>>b;
            if(type){adj[a-1].push_back(b-1);}
            edge_list.push_back(make_pair(a-1,b-1));
        }
        vector<int> visited(n,0);
        vector<int> topo;
        bool cq=true;
        for(int i=0;i<n;i++)if(!visited[i]){if(cycle(i,adj,topo,visited)){cq=false;break;}}
        if(cq)
        {
            pyes;ce;
            vector<int >idx(n,-1);
            for(int i=0;i<topo.size();i++)
            {
                idx[topo[i]] =i;
            }
           
            for(auto x:edge_list)
            {
                int a= x.first;
                int b= x.second;
                if(idx[a]>idx[b]){cout<<a+1<<" "<<b+1;}
                else cout<<b+1<<" "<<a+1;
                ce;
            }
        }
        else{ pno;ce;}
       
    }

    return 0;
}
