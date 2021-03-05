/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root == nullptr) return nullptr;

        NodeCopy* cur = new NodeCopy(root->val);
        old_to_new[root] = cur;
        for (NodeCopy* pointed : prepare[root]) {
            pointed->random = cur;
        }
        
        if (old_to_new.count(root->random)) {
            cur->random = old_to_new[root->random];
        } else {
            prepare[root->random].push_back(cur);
        }

        cur->left = copyRandomBinaryTree(root->left);
        cur->right = copyRandomBinaryTree(root->right);
        return cur;
    }
private:
    unordered_map<Node*, vector<NodeCopy*>> prepare;
    unordered_map<Node*, NodeCopy*> old_to_new;
};
