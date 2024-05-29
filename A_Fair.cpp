#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,s;
    scanf("%d%d%d%d",&n,&m,&k,&s);
    vector<int> goods(n);
    for(int i=0;i<n;i++){scanf("%d",&goods[i]);goods[i]--;}
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
 
    }
    queue<int> q;
    vector<vector<int> > dist(n,vector<int>(k,INT_MAX));
    for(int j=0;j<k;j++)
    {
        // vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(goods[i]==j)
            {
                // vis[i] = 1;
                q.push(i);
                dist[i][j]=0;
            }
        }
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            for(auto x:adj[top])
            {
                if(dist[x][j]==INT_MAX)
                {
                    // vis[x]=1;
                    dist[x][j] = dist[top][j]+1;
                    q.push(x);
                }
            }
        } 
    
    }
    for(int i=0;i<n;i++)
    {
        nth_element(dist[i].begin(), dist[i].begin() + s, dist[i].end());
        int temp = 0;
        for(int j=0;j<s;j++)
        {
            temp+= dist[i][j];
        }
        cout<<temp<<" "; 
    }
    cout<<endl;
    
}


	