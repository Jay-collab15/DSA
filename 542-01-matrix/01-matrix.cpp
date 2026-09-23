class Solution {
public:
    //Jay
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && ni < m &&
                    nj >= 0 && nj < n &&
                    ans[ni][nj] == -1) {
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return ans;
    }
};