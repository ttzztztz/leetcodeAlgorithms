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
        
        vector<vector<Node*>> layer;
        deque<Node*> q;
        q.push_back(root);
        
        int l = 0;
        while (!q.empty()) {
            layer.push_back(vector<Node*>{});
            int cnt = q.size();
            
            for (int _ = 0; _ < cnt; _++) {
                Node* n = q.front();
                layer[l].push_back(n);
                q.pop_front();
                
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
            
            l++;
        }
        
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 1; j < layer[i].size(); j++) {
                layer[i][j - 1]->next = layer[i][j];
            }
        }
        
        return root;
    }
};
