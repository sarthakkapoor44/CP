#include<bits/stdc++.h>
#include<iterator>
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
     ll arr[n];

     rep(i,n){cin>>arr[i];}
     sort(arr,arr+n);
     unordered_map<ll, ll> count;
     ll occur=1;
     forf(i,0,n-1){if(arr[i+1]!=arr[i]){occur++;}}
    rep(i,n){count[arr[i]]++;}
    set<ll> s1;
    rep(i,n){s1.insert(arr[i]);}
     if(occur>2){
            cout<<"No";
        }
    else{
        if(occur==2){
        ll val1=0;
        ll val2=0;
       set<ll>::iterator itr;
       itr =s1.begin();
       val1= count[*itr];
       itr++;
       val2=count[*itr];
    if(val1-val2==1 || val1-val2==-1 ||val1-val2==0){cout<<"Yes";}
    else{cout<<"No";}
       }

    else{cout<<"Yes";}
    }
     
     ce;
    }
    return 0;
}