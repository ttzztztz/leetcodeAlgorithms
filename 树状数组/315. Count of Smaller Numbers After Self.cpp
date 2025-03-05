class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        data = vector<int>(maxn, 0);
        vector<int> ans(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = query(base + nums[i] - 1);
            incr(base + nums[i], 1);
        }
        return ans;
    }
private:
    const int maxn = 2e4+15, base = 1e4+5;
    vector<int> data;

    int lowbit(int x) {
        return x&(-x);
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += data[x];
            x -= lowbit(x);
        }
        return ans;
    }

    void incr(int x, int val) {
        while (x <= maxn) {
            data[x] += val;
            x += lowbit(x);
        }
    }
};