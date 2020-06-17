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
        while (head) {
            data.push_back(head->val);
            head = head->next;
        }
        d = uniform_int_distribution<int>(0, (int) data.size() - 1);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        const int r = d(rd);
        return data[r];
    }
private:
    mt19937 rd{random_device{}()};
    uniform_int_distribution<int> d;
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
