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
void tower(ll l,ll m,ll r,ll n,ll &count,vp &moves){
    if(n==0){return;}
    tower(l,r,m,n-1,count,moves);
    count++;
    moves.pb(mp(l,r));
    tower(m,l,r,n-1,count,moves);
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        ll n;
        cin>>n;
        ll count=0;
        vp moves;
        tower(1,2,3,n,count,moves);
        cout<<count;ce;
        rep(i,moves.size()){cout<<moves[i].fi<<" "<<moves[i].se;ce;}
        
    }
return 0;
}