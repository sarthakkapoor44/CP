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
 ll n,x,p;
 cin>>n>>x>>p;
ll ans=0;
ll max_= min(2*n,p);
forf(i,1,max_+1){
    ll val = (i*(i+1))/2 +x;
    if(val%n==0){ans=1;break;}
    }
if(ans){cout<<"Yes";}
else{cout<<"No";}ce;
    }
    return 0;
}