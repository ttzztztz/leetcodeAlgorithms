/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            Node* cur_next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = cur_next;
            cur->next->random = cur->random;
            cur = cur_next;
        }

        cur = head;
        while (cur != nullptr) {
            if (cur->next->random) cur->next->random = cur->next->random->next;
            cur = cur->next->next;
        }

        Node* ans = nullptr;
        cur = head;
        while (cur != nullptr) {
            Node* cur_next = cur->next;
            if (ans == nullptr) ans = cur_next;
            if (cur->next) cur->next = cur->next->next;
            cur = cur_next;
        }
        return ans;
    }
};