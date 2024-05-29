#include<bits/stdc++.h>
using namespace std;
// multisource bfs
int n,m;
 
int check(int r,int c)
{
    return (r>=0 && r<n && c>=0 && c<m);
}
char get_letter(pair<int,int> &target,pair<int,int> &src)
{
    if(src.second==target.second)
    {
        if(target.first<src.first)return 'U';
        else return 'D';
    }
    else 
    {
         if(target.second<src.second)return 'L';
        else return 'R';
    }
}
int main()
{
    cin>>n>>m;
    
    vector<vector<int> > shortest(n,vector<int>(m,INT_MAX));
    vector<vector<int> > dist(n,vector<int>(m,INT_MAX));
    vector<vector<pair<int,int> > > path(n,vector<pair<int,int> >(m,{-1,-1}));
    vector<pair<int, int> > dir = {{0, 1},{0,-1},{1,0},{-1,0}};
    vector<vector<char> > grid(n,vector<char>(m));
    queue<pair<int,int> > q;
    pair<int,int> src;
    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')src = {i,j};
            if(grid[i][j]=='M')
            {
                shortest[i][j]=0;
                q.push({i,j});
            }
        }
    }
 
    while(!q.empty())
    {
        pair<int,int> top = q.front();
        q.pop();
        for(auto d:dir)
        {
            int r = d.first + top.first;
            int c = d.second + top.second;
            if(check(r,c) && shortest[r][c]==INT_MAX && grid[r][c]!='#')
            {
                shortest[r][c] =shortest[top.first][top.second]+1;
                q.push({r,c});
            }
        }
    }
    
    q.push(src);
    dist[src.first][src.second] = 0 ; 
    // bool cq1=0;
    while(!q.empty())
    {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        if(dist[curr_r][curr_c]>=shortest[curr_r][curr_c])continue;
        for(auto d:dir)
        {
            int r = d.first + curr_r;
            int c = d.second + curr_c;
            if(check(r,c) && dist[r][c]==INT_MAX && grid[r][c]!='#')
            {
                dist[r][c] =dist[curr_r][curr_c]+1;
                path[r][c] = {curr_r,curr_c};
                q.push({r,c});
            }
        }
    }
    pair<int,int> target = {-1,-1};
    bool cq=0;
    for(int i=0;i<n;i++)
    {
        if(dist[i][0]!=-1 && dist[i][0]<shortest[i][0]){target = {i,0};cq=1;break;}
        if(dist[i][m-1]!=-1 && dist[i][m-1]<shortest[i][m-1]){target = {i,m-1};cq=1;break;}
    }
    if(!cq)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[0][j]!=-1 && dist[0][j]<shortest[0][j]){target = {0,j};break;}
            if(dist[n-1][j]!=-1 && dist[n-1][j]<shortest[n-1][j]){target = {n-1,j};break;}
        }
    }
    if(target.first!=-1 && target.second!=-1)
    {
        cout<<"YES"<<endl;
        stack<char> ans;
        while(target!=src)
        {
            ans.push(get_letter(target,path[target.first][target.second])); 
            target = path[target.first][target.second];
        }
        cout<<ans.size()<<endl;
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
        }
    }
    else
    {
        cout<<"NO";
    }
 
}