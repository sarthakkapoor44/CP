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
int main(){
    int p;
    cin>>p;
    while(p--){
     ll n,m;
     cin>>n>>m;
     string s,t;
     cin>>s>>t;
     ll ans=1;
    
     if(n==1){ans=1;}
     else{
        rep(i,n-1){if(s[i+1]==s[i]){ans=0;break;}}
     
        if(!ans){
            ll cq=1;
            
            if(m!=1){rep(i,m-1){if(t[i+1]==t[i]){cq=0;break;}}}
            if(m%2==0){cq=0;}
         
            if(cq){ ans=1;}
          
            if(ans){
                
              rep(i,n-1){
                if(s[i+1]==s[i]){
                    if(t[0]==t[m-1] && t[0]!=s[i]){ans=1;}
                    
                    else{ans=0;break;}
                }}
            }
        }
     }
   
    

      if(ans){cout<<"Yes";}else{cout<<"No";}ce;
    }
    return 0;
}