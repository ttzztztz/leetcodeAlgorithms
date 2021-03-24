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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* tmp = cur->left;
                while (tmp->right != nullptr && tmp->right != cur) tmp = tmp->right;
                if (tmp->right == nullptr) {
                    tmp->right = cur;
                    answer.push_back(cur->val);
                    cur = cur->left;
                } else { // tmp->right == cur
                    tmp->right = nullptr;
                    cur = cur->right;
                }
            } else {
                answer.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return answer;
    }
};