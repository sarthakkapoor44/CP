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
bool check(ll p,unsigned long long mid,ll arr[],ll n){
unsigned long long val =0;
rep(i,n){val+=mid/arr[i];}
if(val>=p)return true;
return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        ll n,p;
        cin>>n>>p;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        // sort(arr,arr+n);
        ll max_ = *max_element(arr,arr+n);
        unsigned long long  max_time = max_*p;
        unsigned long long upper = 1e18;
       ll right = min(upper,max_time);ll left =0;unsigned long long mid=0;
        unsigned long long ans = 0;
        while(left<=right){
            mid = left + (right-left)/2;
            // cout<<left<<" "<<right;ce;
            if(check(p,mid,arr,n)){ans =mid;right =mid-1;}
            else left =mid+1;
        }
ans  = left + (right-left)/2;
        cout<<ans;
    }
return 0;
}