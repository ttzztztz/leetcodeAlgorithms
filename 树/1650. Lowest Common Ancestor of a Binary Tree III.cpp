/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* left = p, *right = q;
        while (left != right) {
            left = left->parent;
            if (left == nullptr) left = q;

            right = right->parent;
            if (right == nullptr) right = p;
        }

        return left;
    }
};