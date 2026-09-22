class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int initial) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
            image[i][j] != initial || image[i][j] == color)
            return;
        image[i][j] = color;
        dfs(image, i - 1, j, color,initial);
        dfs(image, i, j + 1, color,initial);
        dfs(image, i, j - 1, color,initial);
        dfs(image, i + 1, j, color,initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int initial = image[sr][sc];
        if(initial==color)
            return image;
        dfs(image, sr, sc, color, initial);
        return image;
    }
};