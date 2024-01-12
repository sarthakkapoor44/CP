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
 
     string s;
     cin>>s;
     ll arr[s.length()];
     ll n= s.length();
     forf{arr[i]=0;}
     for(int i=0;i<s.length()-1;i++){
if(s[i+1]==s[i]){
arr[i+1] = arr[i]+1;
}
else{arr[i+1]=arr[i];}
}
//forf{cout<<arr[i]<<" ";}
cout<<endl;
     ll m;
     cin>>m;
while(m--){
    ll a,b;
    cin>>a>>b;
    cout<<arr[b-1]-arr[a-1];
    cout<<endl;
}
    
    return 0;
}