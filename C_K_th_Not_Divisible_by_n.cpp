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
     ll n,k;
     cin>>n>>k;
     ll l=1,r=pow(10,10);ll mid=(l+r)/2;ll cq=0;
     while(l<r){
        ll val;
   //     cout<<"("<<l<<" "<<mid<<" "<<r<<")";
   //    ce;
        mid = (l+r)/2;
        if(mid-mid/n==k){cq=1;break;}
        else if (mid-mid/n >k){r= mid-1;}
        else{l =mid+1;}
       
     }
//cout<<"("<<l<<" "<<mid<<" "<<r<<")";
//ce;
//cout<<cq;
      if(cq){if(mid%n!=0){cout<<mid;}else{if((mid-1) - (mid-1)/n==k){cout<<mid-1;}else{cout<<mid+1;}}}
      else{if(l - l/n==k){cout<<l;}else{cout<<r;}}
   ce;

    }
    return 0;
}