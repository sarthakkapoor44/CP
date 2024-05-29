#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;cin>>n>>k;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){ cin>>arr[i];}
    ll ans  =0;
    ll start=0,end =0;
    map<ll,ll> freq;
    // cout<<ans<<" "<<start<<" "<<end<<endl;
    while(end<n)
    {
       ll val = freq[arr[end]];
       if(!val)freq.erase(arr[end]);
       if(!val && freq.size()==k) 
       {
        while(freq.size()==k)
        {
        
          if(!(--freq[arr[start]])){freq.erase(arr[start]);}
          start++;
          if(start>=n)break;
        }
        cout<<endl;
        }
        freq[arr[end]]++;
        ans+=(end-start+1);
        end++;
        // cout<<ans<<" "<<start<<" "<<end<<" "<<freq.size()<<endl;
    }
    cout<<ans;
}