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
char arr[1000][1000];
ll visited[1000][1000];
pair<ll,ll> path[1000][1000];
#define vp vector<pair<long long, long long> >
int main(){
 ll n,m;
 cin>>n>>m;
 pair<ll,ll> start,end;
 rep(i,n){rep(j,m){cin>>arr[i][j];if(arr[i][j]=='A'){start=mp(i,j);}else if(arr[i][j]=='B'){end =mp(i,j);}}}

 rep(i,1000){rep(j,1000){visited[i][j]=1e18;}}
 queue<pair<ll,ll> > q1;
 q1.push(start);
 visited[start.fi][start.se]=0;

 while(!q1.empty()){
    pair<ll,ll> node  = q1.front();
    ll r= node.fi,c= node.se;
    q1.pop();
    ll distance = visited[node.fi][node.se]+1;
    if(r+1<n && arr[r+1][c]!='#' && visited[r+1][c]>distance){q1.push(mp(r+1,c));visited[r+1][c]=distance;path[r+1][c]=node;}
    if(r-1>=0 &&  arr[r-1][c]!='#' && visited[r-1][c]>distance){q1.push(mp(r-1,c)) ;visited[r-1][c]=distance;path[r-1][c]=node;}
    if(c+1<m && arr[r][c+1]!='#'&& visited[r][c+1]>distance){q1.push(mp(r,c+1));visited[r][c+1]=distance;path[r][c+1]=node;}
    if(c-1>=0 &&  arr[r][c-1]!='#'&& visited[r][c-1]>distance){q1.push(mp(r,c-1));visited[r][c-1]=distance;path[r][c-1]=node;}
 }
 if(visited[end.fi][end.se]!=1e18){
pair<ll,ll> node = end;
stack<pair<ll,ll> > s1;
while(node !=start){
  // cout<<node.fi<<node.se;ce;
    s1.push(node);
    node = path[node.fi][node.se];
}
s1.push(start);
cout<<"YES";ce;
cout<<visited[end.fi][end.se];ce;
pair<ll,ll> curr,next;
while(s1.size()!=1){
    curr = s1.top();s1.pop();next = s1.top();
    if(curr.fi!=next.fi){if(curr.fi>next.fi){cout<<'U';}else{cout<<'D';}}
    else{if(curr.se>next.se){cout<<'L';}else{cout<<'R';}}
    
}
ce;
}
else{cout<<"NO";ce;}
    return 0;
}