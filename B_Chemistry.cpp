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
     string s;
     cin>>s;
     ll ans=0;
     if(n-k==1){ans=1;}
     else{
     map<char,int> m1;
     map<char,int>::iterator itr;
     forf{m1[s[i]]+=1;}
     ll count=0;
     for(itr=m1.begin();itr!=m1.end();itr++){
       if(itr->se%2==1){count++;}
     }
     if(count-k>1){ans=0;}
     if(count-k==0 || count-k==1){ans=1;}
     if(count-k<0){ans=1;}
     }
     if(ans==1){cout<<"YES";}
     else{cout<<"NO";}
     cout<<endl;
}
    return 0;
}