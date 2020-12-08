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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (voyage.empty() || root == nullptr) return kNoAnswer;
        this->voyage_ = voyage;
        
        if (dfs(root)) return ans_;
        else return kNoAnswer;
    }
private:
    vector<int> voyage_;
    vector<int> ans_;
    const vector<int> kNoAnswer = {-1};
    int i = 0;
    bool dfs(TreeNode* u) {
        if (u == nullptr) return true;
        const int v = u->val;
        if (voyage_[i] == v) {
            const int t = ++i;
            
            if (dfs(u->left) && dfs(u->right)) return true;
            ans_.push_back(u->val);
            i = t;
            if (dfs(u->right) && dfs(u->left)) return true;
            
            return false;
        } else return false;
    }
};
