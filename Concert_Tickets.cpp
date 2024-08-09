#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    multiset<ll> s;
    ll num;
    for(int i=0;i<n;i++){cin>>num;s.insert(num);}
    for(int i=0;i<m;i++)
    {
        ll num;cin>>num;
        if(!s.size()){cout<<-1;continue;}
        auto x = s.upper_bound(num);
        if(x != s.begin())--x;
        if(*x<= num && x!=s.end()){cout<<*x<<endl;s.erase(x);}
        else cout<<-1<<endl;
    }

}