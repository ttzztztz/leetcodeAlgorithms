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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head;
        int ans = head->val, cnt = 0;
        while (cur) {
            if (get_random(cnt) == 0) ans = cur->val;
            cnt++;
            cur = cur->next;
        }
        return ans;
    }
private:
    ListNode* head;
    mt19937 rd{random_device{}()};

    int get_random(int u) {
        uniform_int_distribution<int> d(0, u);
        return d(rd);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
