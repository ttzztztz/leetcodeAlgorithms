class TrieNode {
public:
    vector<TrieNode*> next;
    TrieNode() {
        next = vector<TrieNode*>(2, nullptr);
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(), q = queries.size();
        for (int i = 0; i < q; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[1] < rhs[1];
        });
        sort(nums.begin(), nums.end());
        
        root = new TrieNode();
        vector<int> ans(q, -1);
        for (int i = 0, ptr = 0; i < q; i++) {
            const int x = queries[i][0], m = queries[i][1], idx = queries[i][2];
            while (ptr < n && nums[ptr] <= m) {
                insert(nums[ptr]);
                ptr++;
            }

            if (ptr == 0) continue;
            ans[idx] = solve(x);
        }
        return ans;
    }
private:
    TrieNode* root = nullptr;
    void insert(int i) {
        TrieNode* cur = root;
        for (int j = 30; j >= 0; j--) {
            const int t = (i & (1 << j)) ? 1 : 0;
            if (!cur->next[t]) {
                cur->next[t] = new TrieNode();
            }
            cur = cur->next[t];
        }
    }
    
    int solve(int num) {
        int ans = 0;

        TrieNode* cur = root;
        for (int j = 30; j >= 0; j--) {
            const int t = (num & (1 << j)) ? 1 : 0;

            if (cur->next[t ^ 1]) {
                cur = cur->next[t ^ 1];
                ans |= 1 << j;
            } else {
                cur = cur->next[t];
            }
        }
        return ans;
    }
};
