/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ListNodeItem {
public:
    int val;
    ListNode *current;
    ListNodeItem() : val(0), current(nullptr) {};
    ListNodeItem(int v, ListNode* n) : val(v), current(n) {};
    bool operator< (const ListNodeItem& $2) const {
        return this->val > $2.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        priority_queue<ListNodeItem> queue;
        for (auto& node : lists) {
            if (nullptr != node) {
                queue.emplace(node->val, node);
            }
        }
        while (!queue.empty()) {
            ListNodeItem item = queue.top();
            queue.pop();

            if (nullptr != item.current->next) {
                queue.emplace(item.current->next->val, item.current->next);
            }

            if (head == nullptr) {
                head = item.current;
                tail = head;
            } else {
                tail->next = item.current;
                tail = item.current;
            }

        }
        return head;
    }
};