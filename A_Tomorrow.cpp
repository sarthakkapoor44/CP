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
   
     ll M,D;
     ll y,m,d;
     cin>>M>>D>>y>>m>>d;
     ll ans_y,ans_m,ans_d;
    if(d==D){ans_d=1;}else{ans_d= d+1;}
    if(d==D && m==M){ans_y = y+1;ans_m=1;}
    else if(d==D){ans_y=y;ans_m =m+1;}
    else{ans_y=y;ans_m=m;}
    cout<<ans_y<<" "<<ans_m<<" "<<ans_d;
    
    
    return 0;
}