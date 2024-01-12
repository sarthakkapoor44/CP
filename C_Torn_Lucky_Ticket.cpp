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
     ll n;
     cin>>n;
     ll val =n;
     v odd,even;
     rep(i,n){string s;cin>>s;ll sum =0;rep(j,s.length()){sum += 0+ s[j]-48;}if(s.length()%2==0){even.pb(sum);}else{odd.pb(sum);}}
    //rep(i,odd.size()){cout<<odd[i]<<" ";}ce;
    srt(odd);srt(even);
    ll counter=1;
     rep(i,odd.size()){cout<<odd[i]<<" ";}ce;
     rep(i,even.size()){cout<<even[i]<<" ";}ce;
    rep(i,odd.size()-1){if(odd[i+1]==odd[i]){counter++;}else{val+=(counter*(counter-1))/2;counter=1;}}
    counter=1;
    rep(i,even.size()-1){if(even[i+1]==even[i]){counter++;}else{val+=(counter*(counter-1))/2;counter=1;}}
    cout<<val;ce;
    return 0;
}