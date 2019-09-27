class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        unordered_map<int, int> map;

        int sum[nums.size() + 1];
        std::memset(sum, 0, sizeof(sum));

        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        for (int i = 0; i <= nums.size(); i++) {
            int delta = map.count(sum[i]);
            answer += map[sum[i]];
            map[sum[i] + k]++;
        }

        return answer;
    }
};