class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return 0;
        
        int answer = 0, end = 0, bound = 0;
        for (int i = 0; i < N - 1; i++) {
            bound = max(bound, i + nums[i]);
            
            if (i == end) {
                answer++;
                end = bound;
            }
        }
        
        return answer;
    }
};
