#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,q;cin>>n>>q;
    vector<long long> arr(n);
    vector<long long>pre(n+1,0);
    for(long long i=0;i<n;i++){cin>>arr[i];pre[i+1] = pre[i]+arr[i];}
    while(q--)
    {
        long long l,r;cin>>l>>r;
        cout<<pre[r] - pre[l-1]<<endl; 
    }
    return 0;
}