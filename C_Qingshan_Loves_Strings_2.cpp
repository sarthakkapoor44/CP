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
     cin>>n;
     string s;
     cin>>s;
     if(n%2==1){cout<<-1;}
     else{
        ll head=601;
        ll start=602;
        ll end=n+601;
        for(int i=0;i<301;i++){s+="22";s= "22"+s;}
    ll p=0;
    v vect;
    while(start<end){
        if(s[start]!=s[end]){start++;end--;}
        else{
            if(s[start]=='0'){s[end+1]='0';s[end+2]='1';vect.pb(end-head);end+=2;}
            else{s[start-1]='1';s[start-2]='0';vect.pb(start-head-1);start-=2;head-=2;}
            p++;
    }

      if(p>300){break;}
 }
 if(p<=300 && start-end==1){cout<<p;ce;rep(i,vect.size()){cout<<vect[i]<<" ";}}
 else{cout<<-1;}
     }
     ce;
    }
    return 0;
}