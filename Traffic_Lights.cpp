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
    // ll t;cin>>t;
    // while(t--)
    {
        ll x,n;
        cin>>x>>n;
        multiset<ll> inter;
        multiset<ll>::iterator itr;
        set<ll>::iterator itr2;
        set<ll> order;
        order.insert(0);
        order.insert(x);
        inter.insert(x);
        rep(i,n){
            ll num;cin>>num;order.insert(num);
        itr2= order.find(num);
        itr2--;
        ll left = *itr2;
        itr2++;itr2++;
        ll right  =*itr2;
        inter.insert(right-num);
        inter.insert(num-left);
        inter.erase(inter.find(right-left));
        itr = inter.end();
        itr--;
        cout<<*itr<<" ";
        }
       
        
    }
return 0;
}