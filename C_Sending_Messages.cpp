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

int main() {
    // Optimize input/output
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int n,f,a,b;
        cin>>n>>f>>a>>b;
        ll arr[n];
        rep(i,n){cin>>arr[i];}
        ll init =0;
        ll cq=1;
        rep(i,n){
            ll val = a*(arr[i]-init);
            if(val>b){f-=b;}
            else{f-=val;}
            init = arr[i];
            if(f<=0){cq=0;break;}
            
        }
        if(cq){pyes;}else{pno;}ce;
        
    }

    return 0;
}

