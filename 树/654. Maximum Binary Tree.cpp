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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return dfs(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* dfs(const vector<int>& nums, int l, int r) {
        if (l == r) {
            return new TreeNode(nums[l]);
        } else if (l > r) {
            return nullptr;
        }
        
        auto it = max_element(nums.begin() + l, nums.begin() + r + 1);
        const int idx = it - nums.begin();
        
        TreeNode* root = new TreeNode(*it);
        root->left = dfs(nums, l, idx - 1);
        root->right = dfs(nums, idx + 1, r);
        return root;
    }
};
