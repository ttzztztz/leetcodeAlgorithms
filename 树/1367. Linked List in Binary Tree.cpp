/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    vector<int> listVal;
    vector<int> cur;
    bool cmp(vector<int>::iterator start, vector<int>::iterator end) {
        int i = 0;
        while (start != end) {
            if (*start != listVal[i]) return false;
            start++;
            i++;
        }
        return true;
    }
    bool dfs(TreeNode* root) {
        if (root == nullptr) return false;
        cur.push_back(root->val);
        
        if (cur.size() >= listVal.size()) {
            auto it = cur.end() - listVal.size();
            if (cmp(it, cur.end())) return true;
        }
        
        if (root->left) {
            if (dfs(root->left)) return true;
        }
        
        if (root->right) {
            if (dfs(root->right)) return true;
        }
        
        cur.pop_back();
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        while (head) {
            listVal.push_back(head->val);
            head = head->next;
        }
        
        return dfs(root);
    }
};
