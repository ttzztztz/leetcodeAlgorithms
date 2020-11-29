class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        f = vector<int>(target + 1, -1), g = nums;
        
        return dfs(target);
    }
private:
    vector<int> f, g;
    int dfs(int i) {
        if (i == 0) return 1;
        int& val = f[i];
        if (val != -1) return val;
        
        int ans = 0;
        for (int k : g) {
            if (i - k >= 0) ans += dfs(i - k);
        }
        return val = ans;
    }
};
