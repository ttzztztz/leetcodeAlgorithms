class Solution {
public:
    bool dfsTwo(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        if (p->val == q->val) {
            return dfsTwo(p->left, q->left) && dfsTwo(p->right, q->right);
        } else {
            return false;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfsTwo(p, q);
    }
};