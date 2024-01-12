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
     ll l,r,x,a,b;

     cin>>l>>r>>x>>a>>b;
     ll ans=0;
     if(b>a){
     if(b>r){ans=-1;}
     else if(b-a>=x){ans=1;}
     else if(x+b<=r && x+b-a>=x){ans=2;}
     else if(a-x>=l){ans=2;}
     else if(a+x<=r && (a+x)-(a+2*x-b)>=l){ans=3;}
     else{ans=-1;}
     }
     else{
    if(a==b){ans =0;}
    else if(a-b>=x){ans=1;}
    else if(a+x<=r){ans=2;}
    else if(b-x>=l){ans=2;}
    else if(a-x>=l && b+x<=r){ans=3;}
    else{ans=-1;}
     }
cout<<ans<<endl;
    }
    return 0;
}