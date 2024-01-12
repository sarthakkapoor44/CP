#include<bits/stdc++.h>
#include<stack>
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
ll sum=0;
ll arr[1001][1001];
bool visited[1001][1001];
void dfs(pair<ll,ll> pos,ll n,ll m){
ll a = pos.fi;ll b = pos.se;
stack<pair<ll,ll> > s;
s.push(mp(a,b));
while(!s.empty()){
    ll val1 = s.top().fi;
    ll val2= s.top().se;
    s.pop();
    if(!visited[val1][val2]){
    visited[val1][val2]=true;
    
        if(arr[val1][val2]!=0)
          {  
            sum+=arr[val1][val2];
            if(val1-1>=0){s.push(mp(val1-1,val2));}
            if(val2-1>=0){s.push(mp(val1,val2-1));}
            if(val1+1<n){s.push(mp(val1+1,val2));}
            if(val2+1<m){s.push(mp(val1,val2+1));}
            
        }
        }
        }
    }

int main(){
    int t;
    cin>>t;
    while(t--){
    ll n,m;
    cin>>n>>m;
    rep(i,n){rep(j,m){cin>>arr[i][j];visited[i][j]=false;}}
    ll max_sum=-1e18;
    rep(i,n){rep(j,m){if(!visited[i][j]){sum=0;dfs(mp(i,j),n,m);max_sum = max(sum,max_sum);}}}
    cout<<max_sum;
    ce;
    }
    return 0;
}