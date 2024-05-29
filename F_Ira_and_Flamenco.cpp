#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MODN = 1e9+7;
ll modInverse(ll a, ll mod) {
    ll m = mod, y = 0, x = 1;
    while (a > 1) {
        ll q = a / mod;
        ll t = mod;
        mod = a % mod, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m;
    return x%MODN;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        map<ll,ll> freq;
        for(int i=0;i<n;i++)
        {
            ll num;cin>>num;
            freq[num]++;
        }
        ll ans = 0 ;
        if(freq.size()>=m)
        {
            auto start = freq.begin(),end = freq.begin();
            ll temp=1;
            for(int i=0;i<m;i++)
            {
                (temp*= end->second%MODN)%=MODN;
                end++;
                
            }
            end--;
            while(end!=freq.end())
            {
                if(end->first-start->first == m-1)
                {
                   ( ans+= temp%MODN)%=MODN;
                }
                temp = ((temp%MODN) * (modInverse(start->second, MODN)%MODN)) % MODN;;
                start++;
                end++;
                if(end==freq.end())break;
                temp*=end->second;
            }
        }
        cout<<ans<<endl;
    }
    return  0;
}