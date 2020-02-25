/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

#include <list>

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    list<int> temp;
    double target;
    int k;
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        this->target = target, this->k = k;
        dfs(root);
        return vector<int>(temp.begin(), temp.end());
    }
private:
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        
        dfs(node->left);
        if (temp.size() < k) {
            temp.push_back(node->val);
        } else {
            if (abs(temp.front() * 1.0 - target) > abs(node->val - target)) {
                temp.pop_front();
                temp.push_back(node->val);
            }
        }
        dfs(node->right);
    }
};
