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
   ll w,h,n;
   cin>>w>>h>>n;
   ll l=0,r= pow(2,30);
   ll x=0;
    while(l+1<r){
        x =(l+r)/2;
        ll rects = (x/w)*(x/h);
        if(rects==n){break;}
        else if(rects>n){r=x;}
        else{l = x;}
    }
    x= (l+r)/2;
ll rects = (x/w)*(x/h);
if(rects>n){
while(rects>n){x--;rects = (x/w)*(x/h);}x++;}
while(rects<n){x++;rects = (x/w)*(x/h);}
cout<<x;
    return 0;
}