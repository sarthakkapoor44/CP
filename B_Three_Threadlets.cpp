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
        ll n=3;
        ll arr[n];
        forf{cin>>arr[i];}
        sort(arr,arr+n);
        ll count=0;
        ll val;
        while(count<3){
            val=0;
        forf{if(arr[i]>arr[0]){arr[i]-=arr[0];count++;if(count==3){break;}}else{val++;}}
    if(val==3){break;}
        }
       if(arr[1]==arr[0] && arr[1]==arr[2] && arr[2]==arr[0]){cout<<"YES";}
       else{cout<<"NO";}
       cout<<endl;
    }
    return 0;
}