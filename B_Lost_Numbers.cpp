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
/*ll gcd(ll a, ll b) {if (!a || !b);return a | b;
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
    ll prod[4];
    cout<<"? 1 2";ce;
    cout<<flush;
    cin>>prod[0];
    cout<<"? 2 3";ce;
    cout<<flush;
    cin>>prod[1];
    cout<<"? 3 4";ce;
    cout<<flush;
    cin>>prod[2];
    cout<<"? 4 5";ce;
    cout<<flush;
    cin>>prod[3];
    v vect = {4,8,15,16,23,42};
    ll ans=1;
    while(ans){
        ans=0;
        rep(i,5){if (prod[i] != vect[i]*vect[i+1]){ans=1;break;}}
        if(ans){next_permutation(vect.begin(),vect.end());}

    }
cout<<"! ";
rep(i,6){cout<<vect[i]<<" ";}ce;
cout<<flush;
return 0;
}