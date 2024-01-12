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
     ll n;
     cin>>n;
     ll ip[n];
     forf{cin>>ip[i];}
     ll perm  = pow(2,n);
  
     ll arr[perm][n];
        for(int j=0;j<n;j++){
            for(int i=0;i<perm;i++){arr[i][j]=-1;}}
       
       for(int j=0;j<n;j++){
            for(int i=1;i<perm;i++){
                ll val = pow(2,j);
      if(i%val==0){
        if(arr[i-1][j]==1)arr[i][j]=-1;
        else arr[i][j]=1;
      }
      else{arr[i][j]=arr[i-1][j];}
     }
        }
        ll ans=0;
          for(int i=1;i<perm;i++){
            ll sum=0;
            for(int j=0;j<n;j++){
                sum+= arr[i][j]*ip[j];
            }
            if(sum%360==0){ans=1;break;}
          }
          if(ans){cout<<"YES";}
    else{cout<<"NO";}
    cout<<endl;
     
    
    return 0;
}