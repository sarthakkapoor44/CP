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
        ll arr[2*n];
        vp odd,even;
        rep(i,2*n){cin>>arr[i];if(arr[i]%2==1){odd.pb(mp(arr[i],i));}else{even.pb(mp(arr[i],i));}}
        if(even.size()>0 && even.size()%2==1){even.pop_back();odd.pop_back();}
        else if(even.size()>0){even.pop_back();even.pop_back();}
        else{odd.pop_back();odd.pop_back();}
        for(int i =0;i<odd.size();i+=2){cout<<odd[i].se+1<<" "<<odd[i+1].se+1;ce;}
        for(int i =0;i<even.size();i+=2){cout<<even[i].se+1<<" "<<even[i+1].se+1;ce;}

ce;
    }
return 0;
}