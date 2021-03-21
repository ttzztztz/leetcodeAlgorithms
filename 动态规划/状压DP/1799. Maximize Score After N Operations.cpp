class Solution {
public:
    int maxScore(vector<int>& nums) {
        this->nums = nums;
        memset(f, 0xff, sizeof f);
        return dfs(0, 15);
    }
private:
    int f[(1 << 14) + 5][16];
    vector<int> nums;
    int dfs(int state, int select1) {
        if (state == (1 << nums.size()) - 1) return 0;
        int& val = f[state][select1];
        if (val != -1) return val;
        int ans = 0;
        
        const int t = __builtin_popcount(state);
        for (int i = 0; i < nums.size(); i++) {
            if (state & (1 << i)) continue;
            
            if (select1 == 15) {
                ans = max(ans, dfs(state | (1 << i), i));
            } else {
                const int x = (t / 2) + 1;
                const int score = x * __gcd(nums[i], nums[select1]);
                ans = max(ans, score + dfs(state | (1 << i), 15));
            }
        }
        return val = ans;
    }
};
