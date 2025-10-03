#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,y;
    cin>>n>>x>>y;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    long long ans =0;
    if(x>y)
    {
        ans = n;
        cout<<ans;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>x)break;
        if((i%2))arr[i]+=y;
        if(arr[i]<=x)ans++;
    }
    cout<<ans;
    return 0;
}