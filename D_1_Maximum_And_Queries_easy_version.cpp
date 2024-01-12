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
ll bits[1000001];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    {
        ll n,q;
        cin>>n>>q;
        ll arr[n];rep(i,n)cin>>arr[i];
        int max_set=INT_MIN;

        rep(i,n){
            ll num=arr[i];
            int count=0;
            while(num!=0){count++;num= num>>1;}
            max_set = max(max_set,count);
        }
        // cout<<max_set;ce;
        // rep(i,n){cout<<arr[i];}       
        rep(i,n){
            ll val=1;
            ll num =arr[i];
            ll count=1;
            rep(j,max_set){
            if((num&1)==0){bits[count]+=val;val*=2;}
            count*=2;
            num = num>>1;
          }  
           }
        ll max_num=0;
        rep(i,max_set){
            max_num += pow(2,i);
        }
        // cout<<max_num;ce;
        forf(i,1,max_num+1){
            ll val=1;
            if(bits[i]==0){
            rep(j,max_set){
                    if((val&i)){bits[i]+=bits[val];}
                    val = val<<1;
            }
            }
        }
        // forb(i,max_num,1){if(bits[i-1]>bits[i]){bits[i-1] =bits[i]; }}
        
        forf(i,1,max_num+1){cout<<bits[i]<<" ";}ce;
        rep(i,q){
            ll a;cin>>a;
            auto x = lower_bound(bits,bits+max_num+1,a);
            if(x==bits+max_num+1){x--;}
            if(*x>a){x--;}
            
             ll index = x-bits;
            cout<<index;ce;
        }
    }
return 0;
}