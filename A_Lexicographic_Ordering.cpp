#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
const long long MOD = 1e9 + 7;
long long modpow(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long modinv(long long q)
{
    return modpow(q, MOD - 2);
}

ll binpow(ll a, ll b, ll M)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= M;
        b >>= 1;
        (a *= a) %= M;
    }
    return res;
}

bool power_10(string n){
    ll cq = (n[0]=='1');
    for(int i =1;i<n.size();i++){
        if(n[i]!='0')return 0;
    }
    return cq;
}
int main()
{
    ll t;
    cin >> t;
    ll mx = 17;
    ll num = 1;
    vector<ll> pows = {1};
    for (int i = 1; i <= mx; i++)
    {
        num *= 10;
        pows.push_back(pows.back() + num);
    }
    while (t--)
    {
        ll n;
        cin >> n;
        bool cq = 1;
        if (n == 1)
            cq = 0;
        else
        {   
            string val = to_string(n);
            if(power_10(val))cq=0;
            ll sz = val.size();
            ll cnt = 0;
            for (int i = 0; i < sz; i++)
            {
                if (cnt >= 2020)
                    break;
                if (i != sz - 1)
                    cnt++;
                if (i == 0)
                {
                    cnt += (ll(val[i] - '0') - 1) * (pows[sz - i - 1]);
                }
                else
                {
                    cnt += (ll(val[i] - '0')) * (pows[sz - i - 1]);
                }
                // cout << i << "," << cnt << endl;
            }
            if (cnt >= 2020)
                cq = 0;
        }
        if (cq)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}