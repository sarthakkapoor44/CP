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
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n,m;
     cin>>n>>m;
     char arr[n][m];
     for(ll i =0;i<n;i++){
        for (ll j = 0; j <m; j++)
        {
            cin>>arr[i][j];
        }
        }
    ll row[n],col[m];
    for(ll i=0;i<n;i++){
        ll sum=0;
        for(ll j=0;j<m;j++){
           if(arr[i][j]=='U'|| arr[i][j]=='D'){
            sum+= 1;}
        }
        row[i]=sum;
    }
    
     for(ll j=0;j<m;j++){
        ll sum=0;
        for(ll i=0;i<n;i++){
              if(arr[i][j]=='R'|| arr[i][j]=='L'){
            sum+= 1;}
        }
        col[j]=sum;
    }
    ll ans=1;
    for(int i=0;i<n;i++){if(row[i]%2==1){ans=0;break;}}
    for(int i=0;i<m;i++){if(col[i]%2==1){ans=0;break;}}
    if(ans){
        char array[n][m];
        for(ll i=0;i<n;i++){
            ll count=0;
        for(ll j=0;j<m;j++){
         if(arr[i][j]=='R'){array[i][j]='W';}
         else if(arr[i][j]=='L'){array[i][j]='B';}
         else if(arr[i][j]=='U'){if(count%2==0){array[i][j]='B';array[i+1][j]='W';}else{array[i][j]='W';array[i+1][j]='B';}count++;}
         else if(arr[i][j]=='.'){array[i][j]='.';
         }
        
        }
     }
      
        for(ll j=0;j<m;j++){
            ll count=0;
        for(ll i=0;i<n;i++){
         if(arr[i][j]=='L'){if(count%2==0){array[i][j]='B';array[i][j+1]='W';}else{array[i][j]='W';array[i][j+1]='B';}count++;}
         else if(arr[i][j]=='.'){array[i][j]='.';}
        }
     }
for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
        cout<<array[i][j];
     }
     cout<<endl;
    }
        }
        else{cout<<-1<<endl;}    }
    return 0;
 }