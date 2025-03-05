class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> ans(n, 0);

        vector<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            const int t = temperatures[i];

            while (!stk.empty() && temperatures[stk.back()] <= t) stk.pop_back();
            if (!stk.empty()) ans[i] = stk.back() - i;
            else ans[i] = 0;
            stk.push_back(i);
        }

        return ans;
    }
};