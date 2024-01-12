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
const ll MODN= 1e9 + 7;
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
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        forf(i,0,n)cin>>arr[i];
        v vect;
        ll last =0;
        ll i=0;
        ll sum=0;
        while(i<n)
        {

if(last<arr[i]){sum++;vect.pb(sum);last=arr[i];}
else{
   sum++;
last =min(arr[i],last);
   while(i+1<n && arr[i+1]<=last){vect.pb(sum);last =min(arr[i],last);i++;}
    last = min(arr[i],last);
   vect.pb(sum);
   
}
i++;
// cout<<last;ce;
        }
//  rep(i,vect.size()){cout<<vect[i]<<" ";}ce;
rep(i,q){
    ll a,b;cin>>a>>b;
    ll val = min(b-a+1,2ll);
    ll val2 = vect[b-1]-vect[a-1]+1;
    if(a+1<=b && vect[a]-vect[a-1]==0){val2++;}
    if(a-2>=0 && vect[a-2]==vect[a-1]){val2++;}
    cout<<max(val,val2);ce;

}
    }
return 0;
}