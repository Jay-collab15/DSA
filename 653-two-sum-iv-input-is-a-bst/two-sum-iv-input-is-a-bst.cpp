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
    stack<TreeNode*> next;
    stack<TreeNode*> before;
    void pushLeft(TreeNode* root) {
        while (root) {
            next.push(root);
            root = root->left;
        }
    }
    void pushRight(TreeNode* root) {
        while (root) {
            before.push(root);
            root = root->right;
        }
    }
    int getNext() {
        TreeNode* node = next.top();
        next.pop();
        int val = node->val;
        pushLeft(node->right);
        return val;
    }
    int getBefore() {
        TreeNode* node = before.top();
        before.pop();
        int val = node->val;
        pushRight(node->left);
        return val;
    }
    bool findTarget(TreeNode* root, int k) {
        pushLeft(root);
        pushRight(root);
        int i = getNext();
        int j = getBefore();
        while (i < j) {
            if (i + j == k) {
                return true;
            }
            if (i + j < k) {
                i = getNext();
            }
            else {
                j = getBefore();
            }
        }
        return false;
    }
};