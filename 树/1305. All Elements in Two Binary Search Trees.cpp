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
    vector<int> answer;
    void dfs(TreeNode* u) {
        if (u == nullptr) return;
        answer.push_back(u->val);

        dfs(u->left);
        dfs(u->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1), dfs(root2);

        sort(answer.begin(), answer.end());
        return answer;
    }
};