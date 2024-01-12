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
     string s;
     cin>>s;
     ll start =1;
     ll dir =1;
     rep(i,k){
        if(s[i]=='R'){dir= -1*dir;if(dir==1){start++;}else{start--;}}
        else if(s[i]=='U'){if(dir==1){start++;}else{start--;}}
        else if(s[i]=='S'){if(dir==1){start+=2;}else{start-=2;}}
    if(start>n){start=start%n;}
    else if(start<1){start+=n;}
     }
     cout<<start<<endl;
    }
    return 0;
}