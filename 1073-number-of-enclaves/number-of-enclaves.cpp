class Solution {
public:
    // Jay
    void dfs(vector<vector<int>>& vis, int i, int j) {
        int m = vis.size();
        int n = vis[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == 0)
            return;
        vis[i][j] = 0;
        dfs(vis, i - 1, j);
        dfs(vis, i, j + 1);
        dfs(vis, i + 1, j);
        dfs(vis, i, j - 1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis = grid;
        int m = vis.size();
        int n = vis[0].size();
        for (int i = 0; i < n; i++)
            dfs(vis, 0, i);
        for (int i = 0; i < m; i++)
            dfs(vis, i, n - 1);
        for (int i = n - 1; i >= 0; i--)
            dfs(vis, m - 1, i);
        for (int i = m - 1; i >= 0; i--)
            dfs(vis, i, 0);
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};