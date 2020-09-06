class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            answer.push_back(nums[i] + answer[i - 1]);
        }
        return answer;
    }
};
