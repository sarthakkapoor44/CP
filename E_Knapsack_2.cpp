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
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//    tree_order_statistics_node_update> ost;
const ll MODN = 1e9 + 7;
const ll MAXN = 1000001;

ll dp[101][100001];
int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    {   //Lesgooooooo!!!!
        ll n,w;
        cin>>n>>w;
        vp comb(n);
        rep(i,n)
        {
            cin>>comb[i].fi>>comb[i].se;
        }
     
        rep(i,101)
        {
            rep(j,100001) dp[i][j]=INF;
        }
        dp[0][0]=0;
        forf(i,1,n+1)
        {
            rep(j,100001)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j]);
                if(j+comb[i-1].se<=100000)
                    {
                    dp[i][j+comb[i-1].se]=min(dp[i][j+comb[i-1].se],dp[i-1][j]+comb[i-1].fi);
                    }
            }
        }
        forb(j,100000,0)
        {
            if(dp[n][j]<=w){cout<<j;ce;break;}
        }
    }

    return 0;
}

