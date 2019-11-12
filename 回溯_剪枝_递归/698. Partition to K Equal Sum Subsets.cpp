class Solution {
public:
    int K, N, avg;
    bool dfs(vector<int>& nums, vector<int>& bucket, int element) {
        if (element < 0) {
            return true;
        }
        for (int i = 0; i < K; i++) {
            // ¼ôÖ¦2
            if (bucket[i] == nums[element] || (element > 0 && bucket[i] - nums[element] >= nums[0])) {
                bucket[i] -= nums[element];
                if (dfs(nums, bucket, element - 1)) {
                    return true;
                }
                bucket[i] += nums[element];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        N = nums.size(), K = k;

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k) {
            return false;
        }
        avg = sum / k;
        sort(nums.begin(), nums.end());

        // ¼ôÖ¦1
        for (int num : nums) {
            if (num > avg) {
                return false;
            }
        }

        vector<int> bucket(K, avg);
        return dfs(nums, bucket, N - 1);
    }
};