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
        string s;
        cin>>s;
        map<pair<ll,ll>,ll> pos;
        pair<ll,ll> ans = mp(0,0);
        pair<ll,ll> curr = mp(0,0);
        ll len = INT_MAX;
        pos[curr]=1;
        rep(i,n){
        if(s[i]=='R'){curr.fi+=1;}
        if(s[i]=='L'){curr.fi-=1;}
        if(s[i]=='D'){curr.se-=1;}
        if(s[i]=='U'){curr.se+=1;}
        if(pos[curr]!=0){
            if(abs(pos[curr]-(i+2))<len){len = abs(pos[curr]-i-2);ans = mp(pos[curr],i+1 );}
        }
        pos[curr] =i+2;
        }
        if(ans.fi>0 && ans.se>0){
        cout<<ans.fi<<" "<<ans.se;ce;
        }
        else{cout<<-1;ce;}
    }
return 0;
}