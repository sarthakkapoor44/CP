#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define forf for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define vp vector<pair<long long, long long> >
void dfs(int pos,unordered_map<int,bool> &visited, unordered_map<int,vector<int> > adj,unordered_map<int,vector<int> >&ans,ll count){
if(!visited[pos]){
    visited[pos]=true;
    ans[count].push_back(pos);
    for(auto x:adj[pos])
    {
        dfs(x,visited,adj,ans,count);
    }
}

return;
}
int main(){
   ll n,m,k;
   cin>>n>>m>>k;
   unordered_map<int,bool> special;
   for(int i=0;i<k;i++){ll num;cin>>num;special[num]=true;}
   unordered_map<int,bool> visited;
   for(int i=0;i<=n;i++){visited[i]=false;}
   unordered_map<int,vector<int> > adj;
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   //cout<<endl;
   /*for(int i=1;i<=n;i++){
    cout<<i<<"->";
    for(auto x:adj[i]){cout<<x<<" ";}
    cout<<endl;
   }*/
   unordered_map<int,vector<int>> ans;
   ll count=0;
   for(int i=1;i<=n;i++){
    if(!visited[i]){
   dfs(i,visited,adj,ans,count);
   count++;
}
   }
   ll out=0;ll sum=0;

  vector<pair<int,int> > val,val2;
  for(int i=0;i<count;i++){
    val.push_back(make_pair(0,0));
    val2.push_back(make_pair(0,0));
  } 

   for(int i=0;i<count;i++){
    val[i].fi = ans[i].size();
    for(auto x:ans[i]){
        if(special[x]){
            val[i].se+=1;
            sum++;
            if(val[i].se>1){out= -1;}
        }
    }
   }
   sort(val.begin(),val.end());

for(int i=0;i<count;i++){
    val2[count-i-1].fi= val[i].fi;
    val2[count-i-1].se=val[i].se;
  
}
 vector<pair<ll,ll> > val3;
for(int i=0;i<count;i++){
if(val2[i].fi==1 && val2[i].se==1 ){sum--;}
else{val3.pb(mp(val2[i].fi,val2[i].se));}
}
//for(int i=0;i<val3.size();i++){
//   cout<<val3[i].fi<<" "<<val3[i].se<<endl;
//}
ll total=0;
for(int i=0;i<val3.size();i++){
    if(val3[i].se==0){total+=val3[i].fi;}
}
//cout<<total<<endl<<endl;
   ll left =k-sum;
  // cout<<left<<endl;
   ll maxim=0;
if(out!=-1){
for(int i=0;i<val3.size();i++){
    if(val3[i].second){
        out+= ((val3[i].fi)*((val3[i].fi)-1))/2;
        maxim = max(maxim,val3[i].fi);
    }
   
}
if(maxim!=0){
out -= maxim*(maxim-1)/2;
out+= (maxim+total)*(maxim+total-1)/2;}
else{
    if(left){out+=((total+1)*total)/2;}
else{out+=((total)*(total-1))/2;}
}
 /*if(left){
        out+= ((total))*((total+1))/2;
        left--;
    }
    else{
        out+=(total*(total-1))/2;
    }*/
cout<<out-m;
}
else{cout<<0;}  
   
    return 0;
}