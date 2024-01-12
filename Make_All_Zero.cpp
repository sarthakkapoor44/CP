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
    ll t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];rep(i,n)cin>>arr[i];
        ll min_arr[n];min_arr[0]=arr[0];
        forf(i,1,n){min_arr[i]= min(min_arr[i-1],arr[i]);}
        
    // rep(i,n){cout<<min_arr[i]<<" ";}ce;
        ll tp1=0,tp2=0;
        forb(i,n-1,0){
         
            if(min_arr[i]-tp1>0 && arr[i]-tp1>0 && arr[i]-tp1<(i+1)*(min_arr[i]-tp1)){tp1+=(min_arr[i]-tp1);}
            if(arr[i]-tp1>0){arr[i]=tp1;tp2++;}
           
            // cout<<tp1<<"-->"<<tp2<<" ";
        }
        cout<<min(tp1+tp2,n);ce;
            //   cout<<"--";ce;
    }
return 0;
}