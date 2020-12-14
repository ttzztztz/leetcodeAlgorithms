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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(pre[0]);
        pre.erase(pre.begin());
        post.pop_back();

        const int n = pre.size();
        vector<int> pre1, pre2, post1, post2;

        int i = 0;
        for (; i < n; i++) {
            pre1.push_back(pre[i]);
            post1.push_back(post[i]);
            
            if (pre1.front() == post1.back()) break;
        }

        for (i = i + 1; i < n; i++) {
            pre2.push_back(pre[i]);
            post2.push_back(post[i]);
        }
        
        root->left = constructFromPrePost(pre1, post1);
        root->right = constructFromPrePost(pre2, post2);
        return root;
    }
};
