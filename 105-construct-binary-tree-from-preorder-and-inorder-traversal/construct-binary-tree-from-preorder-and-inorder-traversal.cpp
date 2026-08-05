/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    // Jay
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    map<int, int>& mp, int preStart, int preEnd, int inStart,
                    int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = mp[preorder[preStart]];
        int leftSize = index - inStart;
        root->left = solve(preorder, inorder, mp, preStart + 1,
                           preStart + leftSize, inStart, index - 1);
        root->right = solve(preorder, inorder, mp, preStart + leftSize + 1,
                            preEnd, index + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, mp, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }
};