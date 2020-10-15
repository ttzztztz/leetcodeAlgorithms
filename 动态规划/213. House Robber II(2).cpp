class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
private:
    
    vector<int> cur;
    int solve(const vector<int>& nums, int i, int j) {
        cur.clear();
        for (int k = i; k <= j; k++) cur.push_back(nums[k]);
        int f[105][105];
        memset(f, 0xff, sizeof f);
        f[0][101] = 0;
        int ans = 0;
        
        for (int i = 0; i < cur.size(); i++) {
            for (int j = 0; j <= 101; j++) {
                if (f[i][j] == -1) continue;
                
                f[i + 1][j] = max(f[i + 1][j], f[i][j]);
                ans = max(ans, f[i + 1][j]);
                if (j != i - 1) {
                    f[i + 1][i] = max(f[i + 1][i], f[i][j] + cur[i]);
                    ans = max(ans, f[i + 1][i]);
                }
            }
        }
        
        return ans;
    }

};
