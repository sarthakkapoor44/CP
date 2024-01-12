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
    // ll t;cin>>t;
    // while(t--)
    {
        ll n,m;
        cin>>n>>m;
        string s;cin>>s;
        // ll plain =m;
        ll logo=INT_MIN;
        ll j=0;
        ll max_one=INT_MIN,max_two=INT_MIN;
        while(1){
            ll one=0,two=0;
        while(j<n && s[j]!='0')
        {
            if(s[j]=='1'){one++;}
            if(s[j]=='2'){two++;}
            j++;
        }
        
        logo = max(logo,two+(max(0ll,one-m)));

        j++;
        if(j>=n){break;}
        }
        cout<<logo;
    }
return 0;
}