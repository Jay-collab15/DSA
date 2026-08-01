/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //Jay
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    void findParent(TreeNode* root, TreeNode* par) {
        if (!root) return;
        parent[root] = par;
        findParent(root->left, root);
        findParent(root->right, root);
    }
    void dfs(TreeNode* node, TreeNode* prev, int k) {
        if (!node) return;
        if (k == 0) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != prev)
            dfs(node->left, node, k - 1);
        if (node->right != prev)
            dfs(node->right, node, k - 1);
        if (parent[node] != prev)
            dfs(parent[node], node, k - 1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root, nullptr);
        dfs(target, nullptr, k);
        return ans;
    }
};