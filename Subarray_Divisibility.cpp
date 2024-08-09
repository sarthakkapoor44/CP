#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<0){arr[i] = (n+(arr[i]%n))%n;}
    }
    ll sum = 0;
    map<ll,ll> cnt;
    cnt[0] =1;
    ll ans  = 0;
    for(int i=0;i<n;i++)
    {
        (sum+=arr[i]%n)%=n;
        ans += cnt[(sum)%n];
        cnt[sum] ++;
    }
    cout<<ans;
}