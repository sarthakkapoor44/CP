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
     string s;
     cin>>s;
     ll n=s.length();
     ll arr[n];
     forf{arr[i]=s[i]-48;
     if(arr[i]==0){arr[i]=10;}
     }
     ll count=0;
     ll start=1;
     forf{
        count+= (1 +abs(arr[i]-start));
        start=arr[i];
     }
     cout<<count<<endl;
    }
    return 0;
}