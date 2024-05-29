///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds
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
#define rep(i, n) for (long long i = 0; i < n; i++)
#define forf(i, a, b) for (long long i = a; i < b; i++)
#define forb(i, s, e) for (long long i = s; i >= e; i--)
#define vp vector<pair<ll, ll> >
#define v vector<ll>
#define cin(x) scanf("%lld ",&x)
#define cout(x) printf("%lld ",x)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 200001;

ll dp[MAXN][10];

int main() {
 
   rep(k,MAXN){rep(j,10){dp[k][j]=0;}}
rep(j,10){dp[0][j]=1;}
forf(k,1,MAXN){
            forb(j,9,0){
                if(j<9){(dp[k][j] += dp[k-1][j+1]%MODN)%=MODN;}
                else{(dp[k][j] += (dp[k-1][0]+dp[k-1][1])%MODN)%=MODN;}
            }
        }
    int t=1;
    scanf("%d",&t);
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll sum =0;
        while(n>0){
            (sum += dp[m][n%10])%=MODN;
            n/=10;
        }
        cout(sum);ce;
    }

    return 0;
}
