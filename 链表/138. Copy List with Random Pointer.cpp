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
        
        Node* answer = new Node(head->val);
        Node* old = head->next, *nw = answer;
        mapOldToNew[head] = answer;
        while (old) {
            nw->next = new Node(old->val);
            mapOldToNew[old] = nw->next;
            nw = nw->next;
            old = old->next;
        }
        
        Node* cur = answer;
        old = head;
        while (cur) {
            if (old->random != nullptr) cur->random = mapOldToNew[old->random];
            
            cur = cur->next;
            old = old->next;
        }
        
        return answer;
    }
private:
    unordered_map<Node*, Node*> mapOldToNew;
};
