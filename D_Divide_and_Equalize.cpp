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
     ll sum=1;
     ll arr[n];
     rep(i,n){cin>>arr[i];}
     unordered_map<ll,ll> ump;
     
     for(int j=0;j<n;j++){
        sum = arr[j];
    
       for(ll i=2;i*i<=arr[j];i++){
            while(sum%i==0 && sum>0){sum/=i;ump[i]++;}
       
            if(sum==0 || sum==1){break;}
        }
         if(sum!=0 && sum!=1){ump[sum]++;}
        }
       
        ll ans=1;
        //  for(auto x:ump){
        //      cout<<x.fi<<"->"<<x.se<<" ";
        //  }
        //  ce;
        for(auto x:ump){
            if(x.se%n==0){ans=1;}
            else{ans=0;break;}
        }
        if(ans){cout<<"yes";}else{cout<<"no";}ce;
    }
    return 0;
}