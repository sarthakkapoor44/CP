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
     ll i=2;
     ll cq=0;
     while(i*i<=n){
        if(n%i==0){cq=1;break;}
        i++;
     }
     ll a=1,b=1;
     ll gcd= n/i;
     //if(i%2==0 && cq==1){a= gcd*(i/2);b=gcd*(i/2);}else if(cq==1){a = gcd*((i-1)/2);b=gcd*((i+1)/2);}
     if(cq){a = gcd;b= (i-1)*gcd;}
     else{a= n-1;b=1;}
     cout<<a<<" "<<b;
     ce;
    }
    return 0;
}