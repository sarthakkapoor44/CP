// One day Vasya got hold of information on the Martian dollar course in 
// bourles for the next n days. The buying prices and the selling prices 
// for one dollar on day i are the same and are equal to ai. Vasya has b 
// bourles. He can buy a certain number of dollars and then sell it no more
//  than once in n days. According to Martian laws, one can buy only an integer 
// number of dollars. Which maximal sum of money in bourles can Vasya get by the end of day n?

// Input
// The first line contains two integers n and b (1 ≤ n, b ≤ 2000) — the number of 
// days and the initial number of money in bourles. The next line contains n integers
//  ai (1 ≤ ai ≤ 2000) — the prices of Martian dollars.

// Output
// Print the single number — which maximal sum of money in bourles can Vasya get by the end of day n.
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
 
    ll n,b;
    cin>>n>>b;
    ll arr[n];
    rep(i,n){cin>>arr[i];}
    ll max_ =INT_MIN;
    rep(i,n){
        
        forf(j,i+1,n){
            if(arr[j]>arr[i]){max_ =max(max_,b/arr[i]*(arr[j]-arr[i]) +b);}
            
        }
    }
    cout<<max(max_,b);
   
    return 0;
}