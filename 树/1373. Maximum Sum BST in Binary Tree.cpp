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
    const int INF = 1e6;
    int answer = 0;
    
    int maxSumBST(TreeNode* root) {
        dfs(root);
        
        return answer;
    }
private:
    int calcSum(TreeNode* root) { 
        if (root == nullptr) return 0;
        
        const int sum = calcSum(root->left) + calcSum(root->right) + root->val;
        answer = max(answer, sum);
        return sum;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        if (isBST(root, -INF, INF)) {
            calcSum(root);
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
    }
    bool isBST(TreeNode* root, int left, int right) {
        if (root == nullptr) return true;
        
        return left < root->val && root->val < right && isBST(root->left, left, root->val) && isBST(root->right, root->val, right);
    }
};
