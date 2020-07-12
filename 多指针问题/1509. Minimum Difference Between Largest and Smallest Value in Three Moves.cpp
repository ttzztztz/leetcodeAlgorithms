class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        if (N <= 4) return 0;
        
        
        int answer = nums[N - 1] - nums[0];
        for (int len = 1; len <= 3; len++) {
            for (int left = 0, right = N - len - 1; right < N; left++, right++) {
                answer = min(answer, nums[right] - nums[left]);
            }
        }
        return answer;
    }
};