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
    ll n,m;
    cin>>n>>m;
    ll arr_a[n],arr_b[m];unordered_map<int,int> ump;
    rep(i,n){cin>>arr_a[i];ump[arr_a[i]]+=1;}rep(i,m){cin>>arr_b[i];}
    ll count=0;
    rep(i,m){if(ump[arr_b[i]]>0){count+=ump[arr_b[i]];}}
    cout<<count;

    return 0;
}