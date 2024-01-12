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
     ll n,k;
     cin>>n>>k;
     ll arr[n];
     for (int i = 0; i < n; i++)
     {
      cin>>arr[i]; 
     }
     if(k!=4){
        forf{arr[i]=arr[i]%k;
        if(arr[i]==0){arr[i]=k;}
        }
        sort(arr,arr+n);
        cout<<k-arr[n-1]<<endl;
     }
     else{
       ll  arr2[n];
        forf{arr2[i]=arr[i]%4;
        if(arr2[i]==0){arr2[i]=4;}
     }
     sort(arr2,arr2+n);
     ll ans = 4-arr2[n-1];
     forf{arr[i]=arr[i]%2;
        if(arr[i]==0){arr[i]=2;}
}
sort(arr,arr+n);
if(n>=2){
ans =min(ans,(4-arr[n-1]-arr[n-2]));
}
cout<<ans<<endl;
    }}
    return 0;
}