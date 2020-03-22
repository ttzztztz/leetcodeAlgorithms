class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        const int N = nums.size();
        vector<int> answer;
        
        for (int i = 0; i < N; i++) {
            auto it = answer.begin() + index[i];
            answer.insert(it, nums[i]);
        }
        
        return answer;
    }
};
