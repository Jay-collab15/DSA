class Solution {
public:
    // Jay
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (int next : adj[node]) {
            if (!vis[next]) {
                if (dfs(next, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[next]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];
            adj[prerequisite].push_back(course);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false;
            }
        }
        return true;
    }
};