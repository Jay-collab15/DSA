class Solution {
public:
    //Jay
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                index -= minIndex; 
                if (i == 0) first = index;
                if (i == size - 1) last = index;
                if (node->left)
                    q.push({node->left, 2 * index + 1});
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};