class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> answer;
        
        const int N = nums.size();
        int sum = 0;
        for (int i : nums) sum += i;
        sort(nums.begin(), nums.end(), [](const int& $1, const int& $2)->bool {
            return $1 > $2;
        });
        
        int currentSum = 0;
        for (int i = 0; i < N; i++) {
            currentSum += nums[i];
            answer.push_back(nums[i]);
            if (currentSum * 2 > sum) {
                break;
            }
        }
        
        return answer;
    }
};
