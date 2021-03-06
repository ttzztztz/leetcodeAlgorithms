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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (root1 == nullptr || root2 == nullptr) return false;
        dfs(root1, v1);
        dfs(root2, v2);
        
        int i = 0, j = v2.size() - 1;
        // i-> sum->
        // j<- sum<-
        while (i < v1.size() && j >= 0) {
            if (v1[i] + v2[j] == target) {
                return true;
            } else if (v1[i] + v2[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
private:
    vector<int> v1, v2;
    void dfs(TreeNode* u, vector<int>& v) {
        if (u == nullptr) return;

        dfs(u->left, v);
        v.push_back(u->val);
        dfs(u->right, v);
    }    
};
