class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = 0;
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                answer = max(answer, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        
        return answer;
    }
};
