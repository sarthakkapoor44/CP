#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll sum =  accumulate(arr.begin(),arr.end(),0ll);
    ll left = *(max_element(arr.begin(),arr.end())),right = sum;
    ll ans  = sum;
    
    function<ll(ll)> check = [&](ll mid)->ll{
        ll cnt = 0;
        for(ll i=0;i<n;i++)
        {
            ll sum =0;
            cnt++;
            while(i<n && sum+ arr[i]<=mid)
            {
                sum+= arr[i];
                i++;
            }
            i--;
        }
        return cnt;
    };
 
    while(left<=right)
    {
        ll mid = (left+right)/2;
        if(check(mid)>k){
            left= mid+1;
        }
        else {
            ans =min(ans,mid);
            right = mid-1;
        }
        
    }
    cout<<ans;

    return 0;
}


