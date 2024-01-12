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
     v vect;
     vect.pb(0);vect.pb(1);
     ll i=1;
     while(vect[i]<=n){
        vect.pb(vect[i]+vect[i-1]);
        i++;
     }
     if(k>vect.size()){cout<<0;}
     else{
        ll coeff_1 = vect[k-1];
        ll coeff_2 =vect[k-2];
        ll count=0;
    
        for(int i=0;i<=n;i++){
          ll a = i;
          ll b = (n-a*coeff_2)/coeff_1;
          if(n-a*coeff_2>0 && (n-a*coeff_2)%coeff_1==0){if(a<=b){count++;}}
        }
     cout<<count;
     }
     ce;
    }
    return 0;
}