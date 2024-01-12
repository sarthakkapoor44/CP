#include<bits/stdc++.h>
#include<math.h>
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
     ll n,first,second;
     cin>>n>>first>>second;
     ll ans = 0;
     ll copy=n;
     if((n-1)%second==0){ans=1;}
     else if(first!=1){
        while(copy>1){
        if(copy%first==0){
        copy/=first;}
        else{break;}
        }
        if(copy==1){ans=1;}
    
     }
    if(!ans){
        ll third=first%second;
        int i =1;
    for( i=1;i<=30;i++){
      
if(third==n%second){ans=1;break;}
third=  (third*(first%second))%second;
    }
   for(int j=1;j<=i;j++){n=n/first;}
   if(n==0){ans=0;}
}
if(ans){cout<<"Yes"<<endl;}
else{cout<<"No"<<endl;}
   
    }
    return 0;

}