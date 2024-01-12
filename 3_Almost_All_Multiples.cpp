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
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        rep(i,n){arr[i]=i+1;}
        arr[0]=x;
        arr[x-1] =n;
        arr[n-1]= 1;
         ll index=-1;
        forf(i,x,n-1){
           if(n%(i+1)==0 && arr[i]%(x)==0){index=i;break;}
        }
        if(n%x==0 && index==-1){index=x-1;}
        if(index>0){swap(arr[index],arr[x-1]);}
        if(index>0){rep(i,n){cout<<arr[i]<<" ";}}
        else{cout<<-1;}ce;
    }
return 0;
}