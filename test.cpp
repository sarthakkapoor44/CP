#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<ll,ll> > > adj;
map<ll,ll> freq1,freq2;
ll ans  =0;
const ll MODN = 1e9+7;
void dfs(int pos,int parent)
{

    for(auto x:adj[pos])
    {
        if(x.first==parent)continue;
        if(!(freq1.count(x.second))){freq1[x.second]++;freq2[x.second]++;}
        else
        {
            freq2[x.second]++;
            freq1.erase(x.second);
        }
        (ans+=(freq1.size())%MODN)%=MODN;
        dfs(x.first,pos);
        if(freq2[x.second]-1 == 1)
        {
            freq1[x.second]++;
            freq2[x.second]--;
        }
        else if(!(freq2[x.second]-1))
        {
            freq2.erase(x.second);
            freq1.erase(x.second);
        }
        else {freq2[x.second]--;}
    }
}
int main()
{
    int n;cin>>n;
    adj.clear();
    adj.resize(n);
    for(int i=0;i<n-1;i++)
    {
        ll a,b,w;cin>>a>>b>>w;
        adj[a-1].push_back(make_pair(b-1,w));
        adj[b-1].push_back(make_pair(a-1,w));
    }
    for(int i=0;i<n;i++)
    {   
        freq1.clear();
        freq2.clear();
        dfs(i,-1);
        cout<<endl;
    }
    cout<<(ans/2);
}