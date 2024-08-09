#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll left = 0 ,right =  1e18;
    function<int(ll)> check = [&](ll num)->int{
        ll val =0;
        for(auto x: arr){val += num/x;if(val>=t)break;}
        return (val>= t);
    };
    while(left+1<right)
    {
        ll mid = (left+right)/2;
        if(check(mid))
        {
            right  =mid;
        }
        else left = mid;
    }
    cout<<right;
}