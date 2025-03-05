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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        cnt[0]++;
        dfs(root, 0, targetSum);
        return ans;
    }
private:
    typedef long long ll;
    unordered_map<ll, int> cnt;
    int ans = 0;

    void dfs(TreeNode* root, ll cur, const int target_sum) {
        if (root == nullptr) return;

        cur += root->val;
        if (cnt.count(cur - target_sum)) ans += cnt[cur - target_sum];

        cnt[cur]++;
        dfs(root->left, cur, target_sum);
        dfs(root->right, cur, target_sum);
        cnt[cur]--;
        if (cnt[cur] == 0) cnt.erase(cur);
    }
};