#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    
    ll n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll start = arr[0];
    if(start>1){cout<<1;return 0;}
    ll end =  start;
    for(int i=1;i<n;i++){
        if(arr[i] + start > end+1)
        {   
            if(end+1 != arr[i]){cout<<end+1;return 0 ;}
        }
        end = end+  arr[i];
    }
    cout<<end+1;
    return 0;
}