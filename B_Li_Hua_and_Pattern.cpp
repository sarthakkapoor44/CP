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
     ll arr[n][n];
     rep(i,n){rep(j,n){cin>>arr[i][j];}}
     ll row=0,col=0;
     rep(i,n/2){
        rep(j,n){
            if(arr[i][j]!=arr[n-i-1][n-j-1]){k--;}
            if(k<0){break;}
        }
        if(k<0){break;}
     }
     if(k>=0){
        if(n%2==1){rep(i,n/2){if(arr[n/2][i]!=arr[n/2][n-i-1]){k--;}}}
        if(k>=0){if(k%2==0){cout<<"YES";}else{
            if(n%2==1){cout<<"YES";}else{cout<<"NO";}
        }}else{cout<<"NO";}
     }
     else{cout<<"NO";}
     ce;

    }
    return 0;
}