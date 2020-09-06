class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N = nums.size();
        vector<int> answer(N);
        
        vector<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= nums[stk.back()]) stk.pop_back();
            stk.push_back(i);
        }
        
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= nums[stk.back()]) stk.pop_back();
            
            if (stk.empty()) answer[i] = -1;
            else answer[i] = nums[stk.back()];
            
            stk.push_back(i);
        }
        
        return answer;
    }
};
