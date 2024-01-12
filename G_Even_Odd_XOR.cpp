#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define forf for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define vp vector<pair<long long, long long> >
int main(){
    int t;
    cin>>t;
    while(t--){
     ll n;
     cin>>n;
     ll m = n;
     unordered_map<int,bool> count;
     ll power=0;
     if((m&(m-1))!=0){power++;}
    while(m>1){
        m/=2;
        power++;
    }
    ll ans[n];
    ll p=n;
    if(n%4==2 && n>=6){
      ans[n-1]= 1<<25;
      ans[n-2]= 2<<25;
      ans[n-3] = 3<<25;
      n-=3;
    }
    if(n%2==0){
        ll i=0;
        
        ll val =pow(2,power);
        for(int i=0;i<n;i+=2)

      {  ans[i] =i;
        ans[i+1]= val + (~i);
    
        }
    } 
else{
  ll i=1;
        ll j=n-1;
        ll val =pow(2,power);
        while(i<j){
            ans[i-1]=i;
            ans[j]= val+ (~(i));
            i++;
            j--;
        }
    if((n/2+1)%2==1){
        ans[i-1]= 0;
    }
    else{ans[i-1]=val-1;}
        }
    for(int i=0;i<p;i++){cout<<ans[i]<<" ";}
    cout<<endl;}
    return 0;
}