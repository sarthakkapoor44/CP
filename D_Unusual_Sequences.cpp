#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> binpow(40,0);
const ll MODN = 1e9+7;
map<ll,ll> dp;
ll solve(ll num)
{
    if(num==1)return 1;
    if(dp[num])return dp[num];
    set<ll> factors;
    bitset<40> r = num-1;
    for(int i=2;i*i<=num;i++)
    {
        if(!(num%i))
        {
            factors.insert(i);
            factors.insert(num/i);
        }
    }
    factors.insert(1);
    ll val =1ll;
    for(int i=0;i<40;i++)
    {
        if(r[i])
        {
            (val*=(binpow[i+1]))%=MODN;
        }
    }
    for(auto x:factors)
    {
        val = (val - solve(x)+ MODN)%MODN;
    }
    return dp[num] = val;
}
int main()
{
    binpow[0]=1ll;
    binpow[1]=2ll;
    for(int i=2;i<40;i++)
    {
        binpow[i]= (binpow[i-1]*binpow[i-1])%MODN;
    }
    ll x,y;
    cin>>x>>y;
    if(!(y%x))cout<< solve(y/x);
    else cout<<0;
}