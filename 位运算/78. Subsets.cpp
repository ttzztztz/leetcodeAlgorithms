class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int N = nums.size();
        const unsigned long long MAX_STATE = (1 << N) - 1;
        vector<vector<int>> answer;

        for (unsigned long long state = 0; state <= MAX_STATE; state++) {
            vector<int> oneAnswer;
            for (int i = 0; i < N; i++) {
                if (state & (1 << i)) {
                    oneAnswer.push_back(nums[i]);
                }
            }
            answer.push_back(oneAnswer);
        }

        return answer;
    }
};