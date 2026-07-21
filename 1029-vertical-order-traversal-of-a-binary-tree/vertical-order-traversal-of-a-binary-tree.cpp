class Solution {
public:
    //Jay
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});   
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            mp[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }
        vector<vector<int>> ans;
        for (auto &c : mp) {
            vector<int> temp;
            for (auto &r : c.second) {
                temp.insert(temp.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};