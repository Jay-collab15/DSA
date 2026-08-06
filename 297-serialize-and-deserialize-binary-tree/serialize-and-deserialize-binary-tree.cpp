/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    //Jay
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                ans += "N,";
                continue;
            }
            ans += to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        vector<string> v;
        string s = "";
        for (char c : data) {
            if (c == ',') {
                v.push_back(s);
                s = "";
            }
            else
                s += c;
        }
        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < v.size()) {
            TreeNode* temp = q.front();
            q.pop();
            if (v[i] != "N") {
                temp->left = new TreeNode(stoi(v[i]));
                q.push(temp->left);
            }
            i++;
            if (i < v.size() && v[i] != "N") {
                temp->right = new TreeNode(stoi(v[i]));
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));