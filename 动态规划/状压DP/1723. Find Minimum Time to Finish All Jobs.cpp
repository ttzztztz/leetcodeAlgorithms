class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        this->n = jobs.size(), this->jobs = jobs, this->k = k;
        
        cost = vector<int>(1 << n, 0);
        for (int i = 0; i < (1 << n); i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) c += jobs[j];
            }
            cost[i] = c;
        }
        
        int l = *max_element(jobs.begin(), jobs.end()), r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            if (solve(mid) <= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    int n, k, mx;
    vector<int> jobs, cost, f;
    
    int solve(int max_job) {
        this->mx = max_job;
        f = vector<int>(1 << n, -1);
        return dfs(0);
    }
    
    int dfs(int state) {
        if (state == (1 << n) - 1) return 0;
        int& val = f[state];
        if (val != -1) return val;
        
        int ans = 0x3f3f3f3f;
        const int super = ((1 << n) - 1) & ~state;
        for (int i = super; i; i = (i - 1) & super) {
            if (cost[i] <= mx) {
                ans = min(ans, 1 + dfs(state | i));
            }
        }
        return val = ans;
    }
};
