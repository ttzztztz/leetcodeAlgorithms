class Solution {
public:
    int maximumSum(vector<int>& nums) {
        const int n = nums.size();
        int ans = -1;
        unordered_map<int, int> f;
        for (int i = 0; i < n; i++) {
            const int sd = sum_digit(nums[i]);

            if (f.count(sd)) ans = max(ans, f[sd] + nums[i]);
            f[sd] = max(f[sd], nums[i]);
        }
        return ans;
    }
private:
    int sum_digit(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
};