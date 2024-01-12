#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end
#define mp make_pair
#define pyes cout <<"YES"; 
#define pno cout <<"NO"; 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<long long, long long> >
/*ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}*/
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        ll count_1=0;
        
        rep(i,n){ll num;cin>>num;arr[i]=num%2;if(arr[i]==1){count_1++;}}
        ll ans =0;
        if(count_1>(n+1)/2 || n-count_1>(n+1)/2){ans=-1;}
        else{
        v ones;
        v zeros;
        rep(i,n){if(arr[i]==1){ones.pb(i);}else{zeros.pb(i);}}
        ll temp1=0,temp2=0;
        ll j=0;
        if(ones.size()<zeros.size()){ones =zeros;}
        // rep(i,ones.size()){cout<<ones[i]<<" ";}ce;
        for(ll i =0;i<n;i+=2){if(j>=ones.size()){break;}temp1+=abs(ones[j]-i);j++;}
        j =0;
        if(n>1 && n%2==0){
        for(ll i =1;i<n;i+=2){if(j>=ones.size()){break;}temp2+=abs(ones[j]-i);j++;}
        // cout<<temp1<<" "<<temp2;ce;
        ans = min(temp1,temp2);}
        else{ans =temp1;}
        }
    //  rep(i,n){cout<<arr[i]<<" ";}ce;
         cout<<ans;ce;
    }
    return 0;
    }