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
     if(n==1){cout<<"YES"<<endl;}
     else if(m==1){cout<<"YES"<<endl;}
     else{
     if(m>=n){
        cout<<"NO"<<endl;
     }
     else{
        if(n%m==0){
            cout<<"NO"<<endl;
        }
        else{
            ll val=1;
            ll i=2;
            ll cq=0;
           for(i=2;i*i<=n;i++){
            if(n%i==0){cq=1;break;}
           }
    if(i<=m && cq){val=0;}
            if ((val ))
            {
               cout<<"YES"<<endl;
            }
            else{cout<<"NO"<<endl;}
            
        }
     }
     }
    }
    return 0;
}