/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        deque<Node*> q = {root};
        while (!q.empty()) {
            const int cnt = q.size();
            
            Node* prev = nullptr;
            for (int _ = 0; _ < cnt; _++) {
                Node* u = q.front();
                q.pop_front();
                
                if (prev) prev->next = u;
                prev = u;
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
        }
        
        return root;
    }
};
