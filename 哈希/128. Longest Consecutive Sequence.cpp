class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int mi = *min_element(nums.begin(), nums.end());
        if (mi < 0) {
            for (int& i : nums) i += (-mi);
        }

        bucket_sort(nums);
        const int n = nums.size();
        int ans = 1, cur = 1;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (cnt.count(nums[i] - 1)) {
                cnt[nums[i]] = cnt[nums[i] - 1] + 1;
                ans = max(ans, cnt[nums[i]]);
            } else {
                cnt[nums[i]] = 1;
            }
        }
        return ans;
    }
private:
    typedef long long ll;
    void bucket_sort(vector<int>& nums) {
        const int n = nums.size();
        const int max_nums = *max_element(nums.begin(), nums.end());
        vector<int> buf(n);
        ll exp = 1;
        while (exp <= max_nums) {
            vector<int> cnt(10, 0);
            for (int i = 0; i < n; i++) {
                const int d = (nums[i] / exp) % 10;
                cnt[d]++;
            }
            
            for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
            
            for (int i = n - 1; i >= 0; i--) {
                const int d = (nums[i] / exp) % 10;
                buf[cnt[d] - 1] = nums[i];
                cnt[d]--;
            }
            exp *= 10;
            nums = buf;
        }
    }
};