class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        memset(f, 0xff, sizeof f);
        
        // this->nums.push_back(numeric_limits<int>::min());
        return dfs(0, n, 0);
    }
private:
    int f[1005][1005][2];
    vector<int> nums;
    int n;
    const int INF = 0x3f3f3f3f;
    
    int dfs(int i, int last, int state) {
        if (i == n) return (state == 1 && last != n) ? 0 : INF;
        int& val = f[i][last][state];
        if (val != -1) return val;
        
        int ans = 1 + dfs(i + 1, last, state);
        if (last == n) {
            if (i + 1 < n) {
                if (nums[i] < nums[i + 1]) ans = min(ans, dfs(i + 1, i, state));
            }
        } else {
            const int lv = nums[last];
            if (state == 0) {
                if (lv < nums[i]) ans = min(ans, dfs(i + 1, i, 0));
                else if (lv > nums[i]) ans = min(ans, dfs(i + 1, i, 1));
            } else { // state == 1
                if (nums[i] < lv) ans = min(ans, dfs(i + 1, i, 1));
            }
        }
        
        return val = ans;
    }
};
