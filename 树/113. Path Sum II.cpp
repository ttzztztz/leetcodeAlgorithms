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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ans;
        this->target = targetSum;
        
        cur.push_back(root->val);
        dfs(root, root->val);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;
    int target;
    
    void dfs(TreeNode* u, int sum) {
        if (u->left == nullptr && u->right == nullptr && sum == target) ans.push_back(cur);
        
        if (u->left) {
            cur.push_back(u->left->val);
            dfs(u->left, sum + u->left->val);
            cur.pop_back();
        }
        if (u->right) {
            cur.push_back(u->right->val);
            dfs(u->right, sum + u->right->val);
            cur.pop_back();
        }
    }
};
