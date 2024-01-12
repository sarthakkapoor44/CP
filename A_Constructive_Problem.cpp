#include<bits/stdc++.h>
#include<set>
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
     ll arr[n],arr2[n];
     forf{cin>>arr[i];arr2[i]=arr[i];}
     sort(arr,arr+n);
     ll mex=0;
     forf{if(arr[i]==mex){mex++;}}
     ll bigger =mex;
     forf{if(arr[i]>mex){bigger = arr[i];break;}}
     ll start =0;
     ll end =n-1;
     if(bigger!=mex){
     while(arr2[start]!=bigger && start<n){start++;}
     while(arr2[end]!=bigger && end>=0){end--;}
     for(int i=start;i<=end;i++){arr2[i]=mex;}
    sort(arr2,arr2+n);
    ll mex_next=0;
    forf{if(arr2[i]==mex_next){mex_next++;}}
    if(mex_next==mex+1){cout<<"YES";}
    else{cout<<"NO";}
    
     }
     else {
        ll count=0;
        forf{if(i!=n-1 && arr[i+1]==arr[i]){count++;}}
        if(count){cout<<"YES";}
        else{cout<<"NO";}
     }
     cout<<endl;
    }
    return 0;
}