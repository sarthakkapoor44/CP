#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define mp make_pair
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >

void trav(int src,vp &adj,ll &min_,string &s,ll &count){
    ll left = adj[src-1].fi;
    ll right = adj[src-1].se;
    if(left!=0 || right !=0){
       ll flag =0;if(right!=0){if(s[src-1]!='R'){count++;flag=1;}else{flag=0;}if(count>min_){count--;return;}trav(right,adj,min_,s,count);}
       if(flag){count--;}
    
       flag=0;if(left!=0){if(s[src-1]!='L'){count++;flag=1;}else{flag=0;}if(count>min_){count--;return;}trav(left,adj,min_,s,count);}
       if(flag){count--;}
    }
    else{
        min_ = min(min_,count);
    
    }
  return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     vp adj;
     rep(i,n){ll l,r;cin>>l>>r;adj.pb(mp(l,r));}
     ll min_=INT_MAX;
     ll count=0;
     trav(1,adj,min_,s,count);
     cout<<min_;ce;
    }
    return 0;
}