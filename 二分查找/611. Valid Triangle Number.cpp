class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 2) return 0;
		sort(nums.begin(), nums.end());

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) continue;
			for (int j = i + 1; j < n; j++) {
				const int s = nums[i] + nums[j];
				auto it = --lower_bound(nums.begin() + j, nums.end(), s);
				ans += max(0, (int) (it - (nums.begin() + j)));
            }
        }
		return ans;
    }
};


