class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        const int N = nums.size();
        vector<int> pre(N + 5, 0);
        for (int i = 1; i <= N; i++) pre[i] = pre[i - 1] + nums[i - 1];
        
        unordered_map<int, int> a;
        a[0] = 0;
        
        int answer = 0, lst = -1;
        for (int i = 1; i <= N; i++) {
            const int t = pre[i] - target;
            if (a.count(t) && lst <= a[t]) {
                answer++;
                lst = i;
                // cout << i << ", " << t << ", " << lst << ", " << pre[i] << ", " << target << endl;
            }
            a[pre[i]] = i;
        }
        
        // cout << endl;
        return answer;
    }
};
