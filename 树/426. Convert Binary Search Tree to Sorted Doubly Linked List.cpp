/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);

        prev->right = ans;
        ans->left = prev;

        return ans;
    }
private:
    Node* ans = nullptr, *prev = nullptr;

    void dfs(Node* root) {
        if (root == nullptr) return;

        dfs(root->left);
        if (ans == nullptr) ans = root;

        if (prev != nullptr) prev->right = root;
        root->left = prev;

        prev = root;
        dfs(root->right);
    }
};