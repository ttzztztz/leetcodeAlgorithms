class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> answer(N);
        
        int prefix = 1;
        for (int i = 0; i < N; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = N - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        
        return answer;
    }
};
