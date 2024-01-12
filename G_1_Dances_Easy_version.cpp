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
     ll n,m;cin>>n>>m;
     ll c[n],b[n];
     c[0]=1;
     forf(i,1,n){cin>>c[i];}
     rep(i,n){cin>>b[i];}
     sort(c,c+n);
     sort(b,b+n);
    //  rep(i,n){cout<<c[i]<<" ";}ce;
    //  rep(i,n){cout<<b[i]<<" ";}ce;
     ll start_b=0,start_c=0,end_b=n-1,end_c=n-1;
     ll count=0;
     while(end_c>=start_c){
        if(c[start_c]<b[start_b] && c[end_c]<b[end_b]){end_b--;end_c--;}
        else{
            end_c--;
            start_b++;
            count++;
        }
     }
     cout<<count;
     ce;
    }
    return 0;
}