#include<bits/stdc++.h>
using namespace std;
signed main()
{
    long long  n;
    cin>>n;
    long long  arr[n];
    long long s = 0;
    long long  sum = 0;
    long long  ans = -1e17;
    for(long long  i=0;i<n;i++){cin>>arr[i];sum+=arr[i];ans =max(ans,sum-s);s=min(s,sum);}
    cout<<ans;
}
