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
    unordered_map<int, int> occur;
    bool judge() {
        int oddCnt = 0;
        for (const auto& p : occur) {
            if (p.second % 2 == 1) {
                oddCnt++;
                if (oddCnt >= 2) return false;
            }
        }
        return true;
    }
    void dfs(TreeNode* u) {
        if (u == nullptr) return;
        occur[u->val]++;
        bool leaf = true;
        if (u->left) {
            dfs(u->left);
            leaf = false;
        }
        if (u->right) {
            dfs(u->right);
            leaf = false;
        }
        
        if (leaf && judge()) answer++;
        occur[u->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return answer;
    }
};
