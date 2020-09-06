class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int answer = 0;
        const int N = nums.size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) answer++;
            }
        }
        
        return answer;
    }
};