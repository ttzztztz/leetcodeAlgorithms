class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const int N = nums.size();
        vector<int> answer(N);
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (nums[j] < nums[i]) answer[i]++;
            }
        }
        
        return answer;
    }
};
