class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int answer = -9999999;
        
        const int N = nums.size();
        deque<int> q;
        vector<int> f(N + 5, -9999999);
        for (int i = 0; i < N; i++) {
            while (!q.empty() && i - q.front() > k) q.pop_front();
            
            f[i] = nums[i] + max(0, q.empty() ? 0 : f[q.front()]);
            answer = max(answer, f[i]);
            
            while (!q.empty() && f[q.back()] < f[i]) q.pop_back();
            q.push_back(i);
        }
        return answer;
    }
};
