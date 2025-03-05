class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        typedef long long ll;

        unordered_map<int, ll> next;
        ll ans = 0;
        for (int task : tasks) {
            ans += 1;
            if (!next.count(task) || next[task] > ans) {
                ans = max(ans, next[task]);
            }
            next[task] = ans + space + 1;
        }
        return ans;
    }
};