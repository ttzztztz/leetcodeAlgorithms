/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int, ListNode*> Value;
        priority_queue<Value, vector<Value>, greater<>> heap;
        for (auto list : lists) {
            if (list != nullptr) heap.emplace(list->val, list);
        }

        ListNode* head = nullptr, *cur = nullptr;
        while (!heap.empty()) {
            auto[_, node] = heap.top();
            heap.pop();

            if (head == nullptr) head = node;
            if (cur != nullptr) cur->next = node;
            cur = node;

            if (node->next != nullptr) heap.emplace(node->next->val, node->next);
        }
        return head;
    }
};