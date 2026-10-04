class Solution {
public:
    // Jay
    bool cycle(vector<vector<int>>& graph, int curr, vector<int>& color) {
        for (auto it : graph[curr]) {
            if (color[it] == -1) {
                color[it] = 1 - color[curr];
                if (!cycle(graph, it, color))
                    return false;
            } else if (color[it] == color[curr])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!cycle(graph, i, color))
                    return false;
            }
        }
        return true;
    }
};