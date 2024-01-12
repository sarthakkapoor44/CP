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
    int t;
    cin>>t;
    while(t--){
     ll n;
     cin>>n;string s;cin>>s;
           ll l=n-1,r=n-1;
           v vect;
           ll cq=1;
    rep(i,n){if(s[i]!='0'){cq=0;break;}}
   
if(!cq){
    forf(i,1,n){
 
     if(s[n-i]!='0'){
        while(l>=0 && r>=0){
            if(s[l]=='0'){break;}
            l--;
        }
        if(l<0){vect.pb(-1);}
        else{
           s[l]='1';
           s[r]='0';

           ll carry=0;
if(vect.size()!=0){carry=vect[i-2];}
           vect.pb((r-l +carry));
        }
        r--;
        if(r<0){break;}
     
     }
     else{
        
        l-=1;
        r-=1;
        if(l<0 || r<0){break;}
        vect.pb(0);
     }
       // cout<<l<<" "<<r<<" ";
    //cout<<s;ce;
    }
    vect.pb(-1);
    }
    else{rep(i,n){vect.pb(0);}}
    rep(i,vect.size()){cout<<vect[i]<<" ";}ce;
    }
    return 0;
}