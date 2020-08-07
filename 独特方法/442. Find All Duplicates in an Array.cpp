class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        const int N = nums.size();
        
        for (int i = 0; i < N; i++) {
            const int v = abs(nums[i]);
            
            if (nums[v - 1] < 0) answer.push_back(v);
            else nums[v - 1] *= -1;
        }
        
        return answer;
    }
};