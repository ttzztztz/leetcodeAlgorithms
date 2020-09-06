class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 0;
        const int N = nums.size();
        
        for (int i = 0; i + 1 < N; i += 2) {
            answer += min(nums[i], nums[i + 1]);
        }
        
        return answer;
    }
};