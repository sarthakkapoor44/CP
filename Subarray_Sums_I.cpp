#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll sum = 0;
    map<ll,ll> cnt;
    cnt[0] =1;
    ll ans  = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        ans += cnt[sum-x];
        cnt[sum] ++;
    }
    cout<<ans;
}