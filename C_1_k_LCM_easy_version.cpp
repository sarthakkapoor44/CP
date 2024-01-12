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
     if(n%2==1){
        cout<<((n-1)/2)<<" "<<((n-1)/2)<<" "<<1;
     }
     else{
     if(n%4==0){cout<<n/4<<" "<<n/4<<" "<<n/2;}
     else{cout<<(n-2)/2<<" "<<(n-2)/2<<" "<<2;}
     }
     cout<<endl;
    }
    return 0;
}