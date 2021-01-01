/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        dfs(e1, root1);
        dfs(e2, root2);
        return e1 == e2;
    }
private:
    unordered_map<char, int> e1, e2;
    void dfs(unordered_map<char, int>& expr, Node* root) {
        if (root == nullptr) return;
        if (root->val == '+') {
            dfs(expr, root->left);
            dfs(expr, root->right);
        } else {
            expr[root->val]++;
        }
    }
};
