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
#define ce cout<<endl
#define all(s) s.begin(), s.end()
#define pyes cout<<"YES";
#define pno cout<<"NO";
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
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n,m;
        cin>>n>>m;
        ll arr[n];
        rep(i,n)cin>>arr[i];
        ll dp[n][m+1];
        rep(i,n){
            rep(j,m+1){
                dp[i][j]=0;
            }
        }
        if(arr[0]){dp[0][arr[0]]=1;}
        else{
            forf(i,1,m+1)dp[0][i]=1;
        }
        forf(i,1,n){
            forf(j,1,m+1){
            if(!arr[i]){
              ( dp[i][j] +=  (dp[i-1][j])%MODN)%=MODN;
              if(j-1>=1) (dp[i][max(1ll,j-1)] += dp[i-1][j]%MODN)%=MODN;
              if(j+1<=m) (dp[i][min(m,j+1)] += dp[i-1][j]%MODN)%=MODN;
            }
            else{
                dp[i][arr[i]]=1;
            }
            }
        }
        forb(i,n-2,0)
        {
            forf(j,1,m+1){
                if(dp[i][j]>0)
                {   ll cq=3;
                    if(dp[i+1][j]==0){cq--;}
                    if(j+1>m){cq--;}
                    else if (dp[i+1][j+1]==0){cq--;}
                    if(j-1<=0){cq--;}
                    else if (dp[i+1][j-1]==0){cq--;}
                 if(!cq){dp[i][j]=0;}
                }
            }
        }
        ll ans=1;
        rep(i,n-1){if(arr[i]==0 || arr[i+1]==0)continue;else{if(abs(arr[i+1]-arr[i])>1)ans=0;break;}}
        ll i=n-1;
        ll val=0;
       while(i>=0){
        val =0;
        if(!arr[i]){
            forf(j,1,m+1){(val+=dp[i][j]%MODN)%=MODN;};
            (ans*=val)%=MODN;
            while(i>=0 && !arr[i])i--;
        }
        else{i--;}
       }
       cout<<ans;ce;
    }

    return 0;
}


