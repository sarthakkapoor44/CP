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
void diff(ll curr,ll arr[],ll n,ll &min_,ll &s1,ll &s2){
    if(curr==n){min_ = min(min_,abs(s1-s2));return; }
    s1+=arr[curr];
    
    diff(curr+1,arr,n,min_,s1,s2);
    s1-=arr[curr];
    s2+=arr[curr];
    diff(curr+1,arr,n,min_,s1,s2);
    s2-=arr[curr];
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        ll sum1=0,sum2=0;
        ll curr =0;ll min_ = INT_MAX;
        diff(curr,arr,n,min_,sum1,sum2);
        cout<<min_;
    }
return 0;
}