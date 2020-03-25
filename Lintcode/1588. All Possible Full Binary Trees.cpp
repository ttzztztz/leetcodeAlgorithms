/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of root
     */
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> answer;
        if (n == 1) {
            return vector<TreeNode*>{new TreeNode()};
        }
        if (n == 0 || !judge(n)) return answer;
        
        if (memo.count(n)) return memo[n];
        
        for (int i = 1; i < n - 1; i++) {
            const int j = n - 1 - i;
            if (!judge(i) || !judge(j)) continue;
            
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(j);
            for (int a = 0; a < left.size(); a++) {
                for (int b = 0; b < right.size(); b++) {
                    TreeNode* root = new TreeNode();
                    root->left = left[a];
                    root->right = right[b];
                    answer.push_back(root);
                }
            }
        }
        
        return memo[n] = answer;
    }
private:
    bool judge(int n) {
        return n % 2 == 1;
    }
};
