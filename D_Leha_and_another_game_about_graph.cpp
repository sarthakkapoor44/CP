#include <vector>
#include <iostream>
using namespace std;

int n, m;
void dfs(int r, int c, vector<vector<int> >& A, vector<vector<int> >& color, vector<vector<int> >& visited) {
    if (!visited[r][c]) {
        visited[r][c] = 1;
        color[r][c] = 1;
        if (r - 1 >= 0 && A[r - 1][c] >= A[r][c]) dfs(r - 1, c, A, color, visited);
        if (c - 1 >= 0 && A[r][c - 1] >= A[r][c]) dfs(r, c - 1, A, color, visited);
        if (r + 1 < n && A[r + 1][c] >= A[r][c]) dfs(r + 1, c, A, color, visited);
        if (c + 1 < m && A[r][c + 1] >= A[r][c]) dfs(r, c + 1, A, color, visited);
    }
}

int solve(vector<vector<int> >& A) {
    if (A.empty() || A[0].empty()) return 0;

    n = A.size(); m = A[0].size();
    int ans = 0;
    vector<vector<int> > red(n, vector<int>(m, 0)), blue(n, vector<int>(m, 0));
    vector<vector<int> > visited(n, vector<int>(m, 0)), visited2(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        if (!visited[i][0]) dfs(i, 0, A, blue, visited);
    }
    for (int j = 0; j < m; j++) {
        if (!visited[0][j]) dfs(0, j, A, blue, visited);
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited2[i][m - 1]) dfs(i, m - 1, A, red, visited2);
    }
    for (int j = 0; j < m; j++) {
        if (!visited2[n - 1][j]) dfs(n - 1, j, A, red, visited2);
    }

    cout << "Blue Matrix:\n";
    for (const auto& row : blue) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    cout << "Red Matrix:\n";
    for (const auto& row : red) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (red[i][j] && blue[i][j]) ans++;
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int> > A(2,vector<int>(2,2));
    int ans = solve(A);
    cout<<ans;
    return 0;
}
