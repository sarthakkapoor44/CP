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
    
   set<char> s1;
  s1.insert('A');
  s1.insert('B');
  s1.insert('C');
vector<string> vs;
rep(i,3){string s;cin>>s;vs.pb(s);}
        rep(i,3){
           string s = vs[i];
           ll val=0;
            rep(j,s.length()){if(s[j]=='?'){val=1;}}
            if(val){rep(j,3){if(s[j]!='?'){s1.erase(s[j]);}}
            set<char>::iterator itr = s1.begin();
            cout<<*itr;ce;
            break;
            }
            
        }
    }
return 0;
}