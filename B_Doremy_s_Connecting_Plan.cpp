#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll sum =arr[0];
        ll cnt =1;
        vector<pair<ll,ll> > left;
        for(int i=1;i<n;i++)
        {
            if(arr[i]+sum>= (i+1)*c)
            {
                sum+=arr[i];
                cnt++;
            }
            else left.push_back(make_pair(c*(i+1)-arr[i],i));
        }
        sort(left.begin(),left.end());
        if(cnt>=2)
        {
            for(int i=0;i<left.size();i++)
            {
              
                ll val = left[i].first;
                ll idx = left[i].second;
                if(sum>=val)
                {
                    sum+=-val+c*(idx+1);
                    cnt++;
                }
              
                
            }
        }
        if(cnt==n)cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    
    }
    return 0;
}