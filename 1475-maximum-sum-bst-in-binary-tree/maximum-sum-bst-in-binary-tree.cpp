/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Jay
    vector<int> solve(TreeNode* root, int &ans) {
        if (root == NULL) {
            return {1, INT_MAX, INT_MIN, 0};
        }
        vector<int> left = solve(root->left, ans);
        vector<int> right = solve(root->right, ans);
        if (left[0] && right[0] &&
            root->val > left[2] &&
            root->val < right[1]) {
            int sum = left[3] + right[3] + root->val;
            ans = max(ans, sum);
            int mini = min(root->val, left[1]);
            int maxi = max(root->val, right[2]);
            return {1, mini, maxi, sum};
        }
        return {0, 0, 0, 0};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};