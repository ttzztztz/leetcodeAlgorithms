class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> p = {0};
        for (int i = 0; i < n; i++) p.push_back(p[i] + nums[i]);
        
        vector<long long> all;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                all.push_back(p[i] - p[j]);
            }
        }
        
        sort(all.begin(), all.end());
        long long answer = 0;
        const int MOD = 1e9+7;
        left--, right--;
        for (int i = left; i <= right; i++) {
            answer += all[i];
            answer %= MOD;
        }
        
        
        return answer;
    }
};