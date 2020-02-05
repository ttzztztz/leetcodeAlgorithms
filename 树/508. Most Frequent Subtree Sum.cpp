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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        int max_appear = 0;
        vector<int> answer;
        dfs(root);
        
        for (auto& p : appear) {
            if (p.second > max_appear) {
                max_appear = p.second;
                answer.clear();
            }
            
            if (p.second == max_appear) {
                answer.push_back(p.first);
            }
        }
        
        return answer;
    }
private:
    unordered_map<int, int> appear;
    int dfs(TreeNode* u) {
        int sum = u->val;
        
        if (u->left) sum += dfs(u->left);
        if (u->right) sum += dfs(u->right);
        
        appear[sum]++;
        return sum;
    }
};
