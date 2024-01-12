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
ll gcd(ll a, ll b) {if (!a || !b)return a | b;
unsigned shift = __builtin_ctz(a | b);
a >>= __builtin_ctz(a);
do {
b >>= __builtin_ctz(b);
if (a > b)
swap(a, b);
b -= a;
} while (b);
return a << shift;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        ll gcd_ ;
        rep(i,n)
        {
        ll num;cin>>num;arr[i]= num-k;
   
        if(i==0){gcd_ =abs(arr[i]);}else{gcd_ = gcd(gcd_,abs(arr[i]));}
        }
        ll neg =1;
        rep(i,n){if(arr[i]>=0){neg=0;break;}}
        if(neg){gcd_=-1*gcd_;}
        // rep(i,n){cout<<arr[i]<<" ";}ce;
     ll ans=0;
     rep(i,n){arr[i]+=k;}
     ll t = gcd_+k;
     rep(i,n){ll num =0;if(t-k!=0){num = (arr[i]-t)/(t-k);} if(num>=0){ans+=num;}else{ans=-1;break;}}
        // rep(i,n){if(arr[i]%gcd_!=0){ans=-1;break;}ans+= abs((arr[i]-gcd_)/gcd_);}
        // rep(i,n){if(arr[i]+k<=gcd_){ans=-1;break;}}
     cout<<ans;ce;
    }
return 0;
}