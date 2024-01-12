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
void permute(vector<char> &ans,string ip,ll length,ll visited[],ll &count,set<string> &permutations)
{   if((long long)ans.size()==length){string s;rep(i,length){s+=ans[i];}permutations.insert(s);count++; return ;}
    rep(i,length){
        
        if(!visited[i]){

            visited[i]=1;ans.pb(ip[i]);
            permute(ans,ip,length,visited,count,permutations);
            ans.pop_back();
            visited[i]=0;
            }
    }
return ;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ll t;cin>>t;
    // while(t--)
    {
        string s;
        cin>>s;
        ll n = s.length();
        vector<char> ans;
        ll visited[n];
        ll count=0;
        set<string> permutations;
        memset(visited,0,sizeof(visited));
        permute(ans,s,n,visited,count,permutations);
        cout<<permutations.size();ce;
        for(auto x:permutations){cout<<x;ce;}
    }
return 0;
}   