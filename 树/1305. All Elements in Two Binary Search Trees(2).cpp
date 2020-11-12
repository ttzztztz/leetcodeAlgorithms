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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1, a1);
        dfs(root2, a2);
        
        return merge();
    }
private:
    vector<int> a1, a2;
    void dfs(TreeNode* u, vector<int>& v) {
        if (u == nullptr) return;

        dfs(u->left, v);
        v.push_back(u->val);
        dfs(u->right, v);
    }
    
    vector<int> merge() {
        vector<int> ans;
        
        const int n = a1.size(), m = a2.size();
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < n && ptr2 < m) {
            if (a1[ptr1] < a2[ptr2]) {
                ans.push_back(a1[ptr1]);
                ptr1++;
            } else {
                ans.push_back(a2[ptr2]);
                ptr2++;
            }
        }
        
        while (ptr1 < n) {
            ans.push_back(a1[ptr1]);
            ptr1++;
        }
        
        while (ptr2 < m) {
            ans.push_back(a2[ptr2]);
            ptr2++;
        }
        return ans;
    }
};
