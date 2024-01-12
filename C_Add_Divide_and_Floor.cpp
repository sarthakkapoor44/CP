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
        rep(i,n){cin>>arr[i];}
        ll count =0;
        ll parity[n];
        memset(parity,0,sizeof(parity));
        ll c=1;
        v addition;
        rep(i,n-1){if(arr[i+1]!=arr[i]){c=0;break;}}
        if(!c){
        while(1)
        {
        ll max= INT_MIN,min =INT_MAX;
        ll maxindex,minindex;
        
        rep(i,n)
        {

            if(arr[i]%2==1){parity[i]=1;}
            else{parity[i]=0;}
            if(min>arr[i]){minindex =i;min = arr[i];}
            if(max<arr[i]){maxindex=i;max= arr[i];}

        }
        ll add=0;
        if(parity[maxindex]==0){add=1;}
        addition.pb(add);
        ll val=0;
        ll cq=1;
        rep(i,n){arr[i] = (arr[i]+add)/2;if(i==0){val=arr[0];}else{if(val!=arr[i]){cq=0;}}}
        // rep(i,n){cout<<arr[i]<<""}
        count++;
        if(cq){break;}
        }}
         cout<<count;ce;
        if(count<=n && addition.size()!=0){
        rep(i,addition.size()){cout<<addition[i]<<" ";}ce;}
       
    }
return 0;
}