/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        root = new Node();
        
        dfs(head, root);
        
        Node* f = root->next;
        // while (f) {
        //     cout << f->val << ", " << (f->child == nullptr ? "nullptr" : "not nullptr") << endl;
        //     f = f->next;
        // }
        if (root->next) root->next->prev = nullptr;
        
        return root->next;
    }
private:
    Node* root;
    Node* dfs(Node* u, Node* prev) {
        prev->next = u;
        if (u == nullptr) return prev;
        u->prev = prev;
        
        Node* nxt = u->next;
        if (u->child) {
            Node* p = dfs(u->child, u);
            u->child = nullptr;
            return dfs(nxt, p);
        } else {
            return dfs(u->next, u);
        }
    }
};
