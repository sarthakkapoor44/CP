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
     ll x,y,k;
     cin>>x>>y>>k;
     if(y<=x){cout<<x;}
     else{
        if(x+k<=y){
        cout<<2*(y-x-k) + x+k;}
        else{
            cout<<y;
        }
     }
     ce;
    }
    return 0;
}