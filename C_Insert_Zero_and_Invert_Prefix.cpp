#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define forf for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define vp vector<pair<long long, long long> >
int main(){
    ll t;
    cin>>t;
    while(t--){
     ll n;
     cin>>n;
     ll arr[n];
     for(ll i=0;i<n;i++){
      cin>>arr[i];
     }
    if(arr[n-1]==1){cout<<"NO";}
    else {
        cout<<"YES"<<endl;
        ll length=0;
        v ans;
        ll i =n-1;
     while(i>=0){
            if(arr[i]==0){ans.pb(0);
           
            i--;
            }
            else{
                ll count=0;
                while(arr[i]==1 && i>=0){i--;count++;}
                ll shift = count;
                count--;
                while(count--){
                    ans.pb(0);
                    
                }
                ans.pb(shift);
                
            }

        }
        for(ll i=0;i<n;i++){cout<<ans[i]<<" ";}
    }
    cout<<endl;
    }
    return 0;
}