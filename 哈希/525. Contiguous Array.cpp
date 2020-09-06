class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int N = nums.size();
        unordered_map<int, int> count;
        
        vector<int> sum0(N + 5, 0), sum1(N + 5, 0);
        count[0] = 0;
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            sum0[i] = sum0[i - 1] + (nums[i - 1] == 0);
            sum1[i] = sum1[i - 1] + (nums[i - 1] == 1);
        }
        
        for (int i = 1; i <= N; i++) {
            const int s = sum1[i] - sum0[i];
            
            if (count.count(s)) {
                answer = max(answer, i - count[s]);
            } else {
                count[s] = i;
            }
        }
        return answer;
    }
};
