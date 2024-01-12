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
 
    {
        string s;cin>>s;
        ll arr[26];
        ll n =s.length();
        memset(arr,0,sizeof(arr));
        rep(i,n){arr[s[i]-'A']+=1;}
        ll odd_count=0;
        ll odd_index=0;
        rep(i,26){if(arr[i]%2==1){odd_count++;odd_index=i;}}
        // cout<<odd_count;ce;
        if((n%2==0 && odd_count==1) || odd_count>1){cout<<"NO SOLUTION";}
        else{
            string ans;
            rep(i,26){
                if(arr[i]!=0){char  a = i+'A';
                
                rep(j,arr[i]/2){ans+=a;}}
            }
        string final = ans;    
        reverse(ans.begin(),ans.end());
        if(odd_count==1){char mid = odd_index+'A';final+=mid+ans;}
        else{final += ans;}
        cout<<final;

        }
    }
return 0;
}