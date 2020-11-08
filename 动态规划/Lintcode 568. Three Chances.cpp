class Solution {
public:
    /**
     * @param nums: an integer array.
     * @return: return the possible longest length of the subarray that elements are the same.
     */
    int threeChances(vector<int> &nums) {
        // write your code here.
        for (int& i : nums) i += 10;
        this->nums = nums;
        this->n = nums.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(0, 3, 0, 0);
    }
private:
    int f[100005][4][2][21];
    int n;
    vector<int> nums;
    
    int dfs(int idx, int last, int start, int num) {
        if (idx == n) return 0;
        int& val = f[idx][last][start][num];
        if (val != -1) return val;
        
        int ans = 0;
        if (start == 0) {
            ans = max(ans, dfs(idx + 1, last, 0, num));
            ans = max(ans, 1 + dfs(idx + 1, last, 1, nums[idx]));
        } else { // start = 1
            if (num == nums[idx]) {
                ans = max(ans, 1 + dfs(idx + 1, last, 1, num));
            } else {
                if (last > 0) ans = max(ans, 1 + dfs(idx + 1, last - 1, 1, num));
                else return 0;
            }
        }
        
        return val = ans;
    }
};
