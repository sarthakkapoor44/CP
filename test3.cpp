int check(int r,int c,int n,int m)
{
return (r>=0 && c>=0 && r<n && c<m);
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int n= A;
    int m = B;
    pair<int,int> src ={C-1,D-1};
    pair<int,int> target ={E-1,F-1};
    queue<pair<int,int> > q;
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX)),vis;
    dis[src.first][src.second]=0;
    q.push(src);
    vector<pair<int,int> > dir ={
        {1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}
    };
    vis[src.first][src.second]=1;
    while(!q.empty())
    {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        for(auto d:dir)

        {
            int r = curr_r +d.first;
            int c=  curr_c +d.second;
            if(check(r,c,n,m) && !vis[r][c])
            {
                vis[r][c]=1;
                dist[r][c] = dist[curr_r][curr_c]+1;
                q.push({r,c});
            }
        }
    }
    return dist[target.first][target.second];
}
