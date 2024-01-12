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
        if(n<3){
            if(n==1){cout<<1;}
            else if(n==2){cout<<2<<" "<<1;}

        }
        else{

            ll mid =(n+1)/2;
            ll arr[n];
            arr[mid-1]=1;
            arr[0]=2;
            arr[n-1]=3; 
            ll val=4;
            forf(i,1,n-1){if(i==mid-1){continue;}else{arr[i]=val;val++;}}
            rep(i,n){cout<<arr[i]<<" ";}
        }
    ce;}
return 0;
}