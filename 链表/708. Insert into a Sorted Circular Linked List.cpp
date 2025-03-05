/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* new_node = new Node(insertVal);
        if (head == nullptr) {
            new_node->next = new_node;
            return new_node;
        }

        Node* max_node = head;
        do {
            if (max_node->val <= max_node->next->val) {
                max_node = max_node->next;
            } else {
                break;
            }
        } while (max_node != head);

        Node* cur = max_node->next, *prev = max_node;
        do {
            if (cur->val <= new_node->val) {
                prev = cur;
                cur = cur->next;
            } else {
                break;
            }
        } while (cur != max_node->next);

        prev->next = new_node;
        new_node->next = cur;
        return head;
    }
};