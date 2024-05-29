///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
#define fi first
#define se second
#define INF 1000000000000000000
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
#define vp vector<pair<ll, ll> >
#define v vector<ll>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;


int main() {

    
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n;
        scanf("%lld",&n);
       ll arr[n];
       ll cnt[n+1];
       rep(i,n){cin(arr[i]);cnt[i]=0;}
       cnt[n]=0;
       rep(i,n){cnt[arr[i]]++;} 
       ll min=INF;
       rep(i,n+1){if(cnt[i]==0){min=i;break;}}
       ll cq=1;
        ll index;
        if(min){
            cq=0;
            set<ll> val;
           
            rep(i,n)
            {
                if(arr[i]<min){val.insert(arr[i]);}
            if(val.size()==min){index=i;break;}
            }
            set<ll> val2;

            forf(i,index+1,n){
                  if(arr[i]<min){val2.insert(arr[i]);}
            if(val2.size()==min){cq=1;break;}
            }
        }
if(cq){
    cout<<2;ce;
    if(min){cout<<1<<" "<<index+1;ce;cout<<index+2<<" "<<n;ce;}
    else{cout<<1<<" "<<n/2;ce;cout<<n/2+1<<" "<<n;ce;}
}
        else{cout<<-1;ce;}

    }

    return 0;
}

