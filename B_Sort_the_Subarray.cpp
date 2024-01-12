#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl; 
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
     cin>>n;
     ll a[n],b[n];
     rep(i,n){cin>>a[i];}
     rep(i,n){cin>>b[i];}
     ll start=0,end=n-1;
     ll min_=+1e18,max_=-1e18;
     rep(i,n){if(a[i]!=b[i]){start=i;break;}}
     forb(i,n-1,0){if(a[i]!=b[i]){end=i;break;}}
     min_ = b[start];
     max_ = b[end];
     forf(i,end+1,n){if(a[i]<max_){break;}else{end++;max_=a[i];}}
     forb(i,start-1,0){if(a[i]>min_){break;}else{start--;min_=a[i];}}
     cout<<start+1<<" "<<end+1;
     ce
    }
    return 0;
}