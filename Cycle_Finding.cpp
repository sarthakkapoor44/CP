#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > edge_list;
    for(int i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;b--;
        edge_list.push_back({a,b,w});
    }
    vector<ll> dist(n,0);
    dist[0]=0;
    vector<ll> parent(n,-1);
    ll last;
    for(int i=0;i<n;i++)
    {
       last=-1;
        for(auto x: edge_list)
        {
            ll a =x[0];
            ll b= x[1];
            ll w = x[2];
            if(dist[a]!=INF && dist[b]>dist[a]+w)
            {
                dist[b] = dist[a]+w;
                last=b;
                parent[b]=a;
            }
        }
    }
    if(last==-1)cout<<"NO";
    else 
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){last=parent[last];}
        vector<long long > cycle;
        ll start = last;
        while(!(cycle.size() && start ==last))
        {   
            cycle.push_back(start);
            start = parent[start];
        }
        cycle.push_back(start);
        reverse(cycle.begin(),cycle.end());
        for(auto x :cycle)cout<<x+1<<" ";
        
    }
}