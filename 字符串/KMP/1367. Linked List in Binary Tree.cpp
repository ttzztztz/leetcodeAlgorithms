/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        while (head) {
            target.push_back(head->val);
            head = head->next;
        }
        build();
        return dfs(root, 0);
    }
private:
    vector<int> target, next;
    void build() {
        next = vector<int>(target.size() + 2, -1);
        next[0] = -1;
        next[1] = 0; // wrong1
        
        int i = 1, j = 0;
        while (i < target.size()) {
            if (j == -1 || target[i] == target[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
    }
    
    bool dfs(TreeNode* root, int idx) {
        if (idx == target.size()) return true;
        if (root == nullptr) return false;
        
        while (!(idx == -1 || root->val == target[idx])) { // wrong2
            idx = next[idx];
        }
        return dfs(root->left, idx + 1) || dfs(root->right, idx + 1);
    }
};