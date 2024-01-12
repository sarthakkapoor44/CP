#include<bits/stdc++.h>
#include<unordered_map>
#include<set>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> paths;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define forf for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define vp vector<pair<long long, long long> >
void path(ll n){
    if(n!=1){ path(paths[n]);cout<<n<<" ";}
   return;
}
int main(){
    
     ll n,m;
     cin>>n>>m;
     unordered_map<ll,vector<pair<ll,ll> >> adj;
     for(ll i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
     }

     ll distance[n+1];
     for(ll i=0;i<n+1;i++){distance[i]=1e18;}
     distance[1]=0;
   
     set<pair<ll,ll> > st;
     st.insert(mp(0,1));
     while(!st.empty()){
        auto top = *(st.begin());
        ll node_dist= top.fi;
        ll node = top.se;
        st.erase(st.begin());
       for(auto neighbour:adj[node]){
        ll neighbour_dist= neighbour.se;
        ll neighbour_node = neighbour.fi;
        if(neighbour_dist+node_dist<distance[neighbour_node]){
            auto replace = st.find(mp(distance[neighbour_node],neighbour_node));
            distance[neighbour_node] = neighbour_dist+node_dist;
            if(replace!=st.end()){st.erase(replace);}
            st.insert(mp(distance[neighbour_node],neighbour_node));
            paths[neighbour_node]= node;
           }
       }
     }
     if(distance[n]==1e18){cout<<-1;}
     else{
        cout<<1<<" ";
     path(n);
     }
    cout<<endl;

    
    return 0;
}