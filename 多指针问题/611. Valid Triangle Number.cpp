class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;

        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = i + 1;
            for (int j = i + 1; j < n; j++) {
                k = max(k, j + 1);
                const int s = nums[i] + nums[j];
                while (k < n && s > nums[k]) {
                    k++;
                }
                ans += k - j - 1;
            }
        }

        return ans;
    }
};


