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
    int distributeCoins(TreeNode* root) {
        auto answer = dfs(root);
        return get<2>(answer);
    }
private:
    tuple<int, int, int> dfs(TreeNode* u) { // {childNodeCount(inclusive), moveRequired}
        if (u == nullptr) return {0, 0, 0};
        tuple<int, int, int> answer = {1, u->val, 0};
        
        if (u->left) {
            auto p = dfs(u->left);
            
            get<0>(answer) += get<0>(p);
            get<1>(answer) += get<1>(p);
            get<2>(answer) += get<2>(p) + abs(get<1>(p) - get<0>(p));
        }
        
        if (u->right) {
            auto p = dfs(u->right);
            
            get<0>(answer) += get<0>(p);
            get<1>(answer) += get<1>(p);
            get<2>(answer) += get<2>(p) + abs(get<1>(p) - get<0>(p));
        }
        
        return answer;
    }
};
