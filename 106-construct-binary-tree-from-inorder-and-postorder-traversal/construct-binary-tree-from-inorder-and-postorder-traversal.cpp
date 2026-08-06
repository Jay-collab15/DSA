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
    TreeNode* solve(vector<int>& postorder, int postSt, int postEd,
                    vector<int>& inorder, int inSt, int inEd, map<int, int>& mp) {
        if (postSt < postEd || inSt > inEd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postSt]);
        int index = mp[postorder[postSt]];
        int leftSize = index - inSt;
        root->left = solve(postorder, postEd + leftSize - 1, postEd, inorder,
                           inSt, inSt + leftSize, mp);
        root->right = solve(postorder, postSt - 1, postEd + leftSize, inorder,
                            index + 1, inEd, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for (int i = 0; i <inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(postorder, postorder.size() - 1, 0, inorder, 0,
                     inorder.size() - 1, mp);
    }
};