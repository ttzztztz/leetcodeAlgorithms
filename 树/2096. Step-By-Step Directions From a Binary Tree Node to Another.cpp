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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        start_val = startValue, dest_val = destValue;
        dfs_parent(root, nullptr);
        find_ans(start_node, nullptr);
        return ans;
    }
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* start_node;
    int start_val, dest_val;
    string ans;
    
    void dfs_parent(TreeNode* cur, TreeNode* par) {
        if (cur == nullptr) {
            return;
        }
        if (cur->val == start_val) {
            start_node = cur;
        }
        parent[cur] = par;
        
        dfs_parent(cur->left, cur);
        dfs_parent(cur->right, cur);
    }
    
    bool find_ans(TreeNode* cur, TreeNode* last) {
        if (cur == nullptr) return false;
        if (cur->val == dest_val) return true;
        
        ans += 'U';
        if (parent[cur] != last && find_ans(parent[cur], cur)) return true;
        ans.pop_back();
        
        ans += 'L';
        if (cur->left != last && find_ans(cur->left, cur)) return true;
        ans.pop_back();
        
        ans += 'R';
        if (cur->right != last && find_ans(cur->right, cur)) return true;
        ans.pop_back();
        
        return false;
    }
};
