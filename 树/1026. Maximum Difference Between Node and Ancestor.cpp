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
    int answer = 0;
    multiset<int> all;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return answer;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            if (all.size() >= 2) {
                answer = max(answer, *all.rbegin() - *all.begin());
            }
            return;
        }
        all.insert(root->val);
        dfs(root->left);
        dfs(root->right);
        all.erase(all.lower_bound(root->val));
    }
};
