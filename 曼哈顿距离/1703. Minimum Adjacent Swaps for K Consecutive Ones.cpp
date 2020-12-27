class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        const int n = nums.size();
        
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                idx.emplace_back(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += abs((idx[i] - i) - (idx[(k - 1) / 2] - (k - 1) / 2));
        }
        
        int cur = ans;
        for (int r = k, l = 0, m = 1 + (k - 1) / 2; r < idx.size(); l++, r++, m++) {
            cur += idx[r] + idx[l] - idx[m];
            
            if (k % 2 == 0) cur -= idx[m];
            else cur -= idx[m - 1];
            
            ans = min(ans, cur);
        }
        
        return ans;
    }
};
