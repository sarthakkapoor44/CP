#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define v vector<long long>
#define se second
#define srt(vect) sort(vect.begin(),vect.end())
#define ce cout << endl 
#define pb push_back
#define all(s) s.begin(),s.end()
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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        ll sign[n];rep(i,n){if(arr[i]==1){sign[i]=-1;}else{sign[i]=1;}}
        ll best=0,sum=0,l=0,r=n-1;
        // rep(i,n){cout<<sign[i]<<" ";}ce;
        ll final_l;
        rep(i,n){
           if(sign[i]>=sum+sign[i]){
            sum= sign[i];
            l=i;
           }
         else{sum =sum+sign[i];}
            if(best<=sum){r=i;final_l=l;}
            best =max(best,sum);
            

        }
        // cout<<l<<" "<<r;ce;
        ll cq=1;
        rep(i,n){if(arr[i]==0){cq=0;}}
        if(cq){arr[0]=0;}
        else{
                forf(i,final_l,r+1){arr[i]=1-arr[i];}}
        ll ans= 0;
        rep(i,n){ans+=arr[i];}cout<<ans;ce;
        
    }
return 0;
}