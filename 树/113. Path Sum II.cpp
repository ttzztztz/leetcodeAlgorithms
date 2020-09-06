/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return answer;
        this->target = sum;
        dfs(root, 0);
        return answer;
    }
private:
    vector<vector<int>> answer;
    vector<int> current;
    int target;
    void dfs(TreeNode* root, int cur) {
        const bool isLeaf = !(root->left) && !(root->right);
        
        if (isLeaf) {
            if (cur + root->val == target) {
                current.push_back(root->val);
                answer.push_back(current);
                current.pop_back();
            }
            return;
        }
        
        if (root->left) {
            current.push_back(root->val);
            dfs(root->left, cur + root->val);
            current.pop_back();
        }
        
        if (root->right) {
            current.push_back(root->val);
            dfs(root->right, cur + root->val);
            current.pop_back();
        }
    }
};
