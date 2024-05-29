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
const ll modn = 998244353;

// for sieve of eratosthenes
// bool is_prime[MAXN];
//void sieve_of_eratosthenes();

// for spf
// int spf[MAXN]; 
// void sieve();

//GCD
// ll gcd(ll a, ll b);

int main() {
    // Optimize input/output (remove if using cin cout exclusively)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while (t--)
    {   //Lesgooooooo!!!!
        ll n,m,k,d;
        cin>>n>>m>>k>>d;
        ll grid[n][m];
        rep(i,n)rep(j,m)cin>>grid[i][j];
        ll dp[n][m];
        rep(i,n)rep(j,m)dp[i][j]=INF;
        rep(i,n)dp[i][0]=1;
        rep(i,n)
        {
            multiset<ll> cnt;
            queue<ll> elts;
            elts.push(dp[i][0]);
            cnt.insert(dp[i][0]);
            forf(j,1,m)
            {   
                ll  min_ = *(cnt.begin());
              
                dp[i][j]= min(dp[i][j],grid[i][j]+1ll+min_);

                elts.push(dp[i][j]);
                if(elts.size()>d+1){
                  cnt.erase(cnt.find(elts.front()));
                    elts.pop();
                    }
                cnt.insert(dp[i][j]);

            }
        }
      
        ll sum =0;
        
        rep(i,k)sum+=dp[i][m-1];
        ll min_sum =sum;
        ll start=0,end = k;
        while(end<n){
            sum=sum -dp[start][m-1]+dp[end][m-1];
            start++;end++;
            min_sum = min(sum,min_sum);
        }
        cout<<min_sum;ce;
      
    }

    return 0;
}
