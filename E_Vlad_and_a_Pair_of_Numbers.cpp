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
     if(n%2==1){cout<<-1;}
     else{v bits;while(n!=0){if(n&1==1){bits.pb(1);}else{bits.pb(0);}n= n>>1;}
    
    //  rep(i,bits.size()){cout<<bits[i]<<" ";}
     ll flag =0;
     v a,b;
     ll flag2=0;
     for(int i=0;i<bits.size();i++){if(bits[i]==0){a.pb(0);b.pb(0);}else{if(flag==0){b.pb(1);flag=1;a.pb(0);}else{flag2=1;a.pb(1);b.pb(0);}}}
     ll sum_a=0;
     for(int i=0;i<a.size();i++){sum_a += a[i]*pow(2,i); }
    ll sum_b=0;
     for(int i=0;i<b.size();i++){sum_b += b[i]*pow(2,i); }
     if(flag && flag2){cout<<sum_a<<" "<<sum_b;}
     else{cout<<-1;}
     }
     ce;
     }
    
    return 0;
}