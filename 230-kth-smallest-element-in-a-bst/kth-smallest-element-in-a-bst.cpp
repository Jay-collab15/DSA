class Solution {
public:
    //Jay
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int ans = -1;
        while (curr != NULL) {
            if (curr->left == NULL) {
                k--;
                if (k == 0)
                    ans = curr->val;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    pred->right = NULL;
                    k--;
                    if (k == 0)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};