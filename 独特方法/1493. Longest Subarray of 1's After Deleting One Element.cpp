class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        bool allOne = true;
        for (int i : nums) {
            if (i != 1) {
                allOne = false;
                break;
            }
        }
        
        if (allOne) return N - 1;
        
        
        vector<int> tmp;
        int prev = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) {
                if (prev > 0) {
                    tmp.push_back(prev);
                    prev = 0;
                }
                tmp.push_back(0);
            } else {
                prev++;
            }
        }
        if (prev > 0) tmp.push_back(prev), prev = 0;
        
        int answer = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (i >= 1 && i + 1 < tmp.size()) {
                answer = max(answer, tmp[i - 1] + tmp[i + 1]);
            }
        }
        return answer;
    }
};