#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
const long long MODN = 1e9 + 7;
long long modpow(long long a, long long b)
{
    long long res = 1;
    a %= MODN;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MODN;
        a = (a * a) % MODN;
        b >>= 1;
    }
    return res;
}

long long modinv(long long q)
{
    return modpow(q, MODN - 2);
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

const ll MAXN = 1e7 + 1;
ll fac[MAXN];
int main()
{
    fac[1] = 1;
    fac[0] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        (fac[i] = (fac[i - 1] * i) % MODN) %= MODN;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (m > n)
        {
            cout << 0;
        }
        else
        {
            ll ans = (fac[n] * modinv(fac[n - m])) % MODN;
            // cout<<ans<<endl;
            ll denom = binpow(2LL, m * (m + 1) / 2, MODN) % MODN;
            // cout<<denom<<endl;
            cout << (ans % MODN * modinv(denom) % MODN) % MODN;
        }
        cout << endl;
    }
}