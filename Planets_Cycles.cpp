///////////////////////////////////////////////////// DYNATOS ////////////////////////////////////////////////////
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
#define vll vector<ll>
#define OPTIMIZE_IO  std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);

 
int main() {
    // FOR GCD - gcd snip
    // FOR SIEVE OF ERATOSTHENES - erat_snip;
    // FOR SPF - spf_snip
    // FOR BINARY_EXPONENTATION - binpow_snip
    OPTIMIZE_IO // Optimize input/output (remove if using scanf and printf)

    {	//Lesgooooooo!!!!
        int n;
        cin>>n;
        int succ[n];int ans[n];
        bool vis[n];
        for(int i=0;i<n;i++)
        {
            cin>>succ[i];
            succ[i]--; 
            ans[i]=-1;
            vis[i]=false;
        }
        vector<int> topo;
        function<void(int)> toposort= [&](int pos)->void{
            vis[pos]=1;
            if(!vis[succ[pos]])
            {
                toposort(succ[pos]);
            }
            topo.pb(pos);
        };
        for(int i=0;i<n;i++){if(!vis[i])toposort(i);}
        for(int j=n-1;j>=0;j--)
        {
            int i =topo[j];
            if(ans[i]==-1)
            {
                int val =i;
                int a=succ[i],b=succ[succ[i]];
                while(a!=b)
                {
                    a = succ[a];
                    b=succ[succ[b]];
                }
                a =  val;
                while(a!=b){a=succ[a];b=succ[b];}
                int mu =a;
                vector<int> cycle_nodes;
                cycle_nodes.pb(mu);
                a= succ[a];int len = 1;
                while(a!=mu){cycle_nodes.pb(a);a=succ[a];len++;}
                for(auto x:cycle_nodes){ans[x]=len;}
                function<int(int)> dfs = [&](int pos)->int
                {
                    if(ans[pos]!=-1)return ans[pos];
                    return ans[pos]= 1+dfs(succ[pos]);
                    
                };
                ans[val] = dfs(val);
            }
        }
        for(int i=0;i<n;i++)std::cout<<ans[i]<<" ";
        
    }

    return 0;
}
