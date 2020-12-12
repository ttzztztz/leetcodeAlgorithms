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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans_;
    }
private:
    unordered_map<string, int> visited_;
    int id_ = 0;
    const int kInvalid = -1;
    vector<TreeNode*> ans_;
    unordered_set<string> used_;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return kInvalid;
        
        const int l = dfs(root->left);
        const int r = dfs(root->right);
        
        string _h = hash(root->val, l, r);
        if (visited_.count(_h)) {
            if (!used_.count(_h)) {
                used_.insert(_h);
                ans_.push_back(root);
            }
        } else {
            visited_[_h] = id_++;
        }
        
        return visited_[_h];
    }

    string hash(int node_val, int left_id, int right_id) {
        return to_string(node_val) + "," + to_string(left_id) + "," + to_string(right_id);
    }
};
