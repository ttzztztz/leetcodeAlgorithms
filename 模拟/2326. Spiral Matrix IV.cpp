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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0, dir = 0;
        const int di[] = {0, 1, 0, -1};
        const int dj[] = {1, 0, -1, 0};

        while (head != nullptr) {
            ans[i][j] = head->val;

            int ni = i + di[dir], nj = j + dj[dir];
            if (!(ni >= 0 && nj >= 0 && ni < m && nj < n && ans[ni][nj] == -1)) {
                dir = (dir + 1) % 4;
                ni = i + di[dir], nj = j + dj[dir];
            }

            head = head->next;
            i = ni, j = nj;
        }
        return ans;
    }
};