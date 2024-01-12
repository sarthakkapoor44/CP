#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//typedef long long int;
#define fi first
#define v vector<int>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 0; i < n; i++)
#define forf(i, a, b) for (int i = a; i < b; i++)
#define forb(i, s, e) for (int i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
void dfs(int pos, unordered_map<int,vector<int> > &adj,unordered_map<int,bool> &visited,vector<int> &comps){
if(!visited[pos]){
    comps.pb(pos);
    visited[pos]=true;
    for(auto x:adj[pos]){
        dfs(x,adj,visited,comps);
    }
}
}
int main(){
   int n,m;
   cin>>n>>m;
   unordered_map<int,vector<int> > adj;
   forf(i,0,m){
    int size;
    cin>>size;
    if(size){
        int a;
        cin>>a;
        size--;
        while(size--){
            int b;
            cin>>b;
            adj[a].pb(b);
             adj[b].pb(a);
        }
       
        }
    }
   
   
   unordered_map<int,bool> visited;
   v comps;
    int sizes[n+1];
    forf(i,1,n+1){
    if(!visited[i]){
     comps.clear();
    dfs(i,adj,visited,comps);
    for(auto x:comps){
     sizes[x]= comps.size();
   }
    }
   }
  
   forf(i,1,n+1){cout<<sizes[i]<<" ";}
   ce;

    return 0;
}