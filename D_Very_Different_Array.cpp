///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define srt(vect) sort(vect.begin(), vect.end())
#define ce printf("\n")
#define all(s) s.begin(), s.end()
#define pyes printf("YES");
#define pno printf("NO");
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vp vector<pair<ll, ll>>
#define v vector<ll>
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;
bool is_prime[MAXN];
int spf[MAXN];

// Function declarations
void sieve();
void sieve_of_eratosthenes();
ll gcd(ll a, ll b);
int main() {
    // Optimize input/output
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    int t=1;
    scanf("%d",&t);
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        v a(n,0),b(m,0);
        rep(i,n){cin>>a[i];}
        rep(i,m){cin>>b[i];}
        srt(a);srt(b);
        ll start1=0,end1=n-1;
        ll start2=0,end2=m-1;
        ll ans=0;
        while(start1<=end1){
       ll val1 = abs(a[start1]-b[start2]);
       ll val2 = abs(a[start1]-b[end2]);
       ll val3=  abs(a[end1]-b[start2]);
       ll val4 = abs(a[end1]-b[end2]);
       if(val1>=val2 && val1>=val3 && val1>=val4){
        start1++;
        start2++;
        ans+=val1;
       }
       else if(val2>=val1 && val2>=val3 && val2>=val4){
        start1++;
        end2--;
        ans+=val2;
       }
       else if(val3>=val1 && val3>=val2 && val3>=val4){
        end1--;start2++;
        ans+=val3;
       }
       else if(val4>=val1 && val4>=val2 && val4>=val3){
        end1--;end2--;
        ans+=val4;
       }
        }
        cout<<ans;ce;
    }

    return 0;
}

