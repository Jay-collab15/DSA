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
    bool isSymmetric(TreeNode* root) {
        return (root==NULL)|| isSymm(root->left,root->right);
    }
    bool isSymm(TreeNode* l,TreeNode* r)
    {
        if(l==NULL||r==NULL)
            return l==r;
        if(l->val!=r->val)
            return false;
        return isSymm(l->left,r->right) && isSymm(l->right,r->left);
    }
};