class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0;
        const int n = hours.size();
        vector<int> pref = {0};
        for (int i : hours) {
            if (i > 8) pref.push_back(pref.back() + 1);
            else pref.push_back(pref.back() - 1);
        }
        
        vector<int> stk;
        for (int i = 0; i <= n; i++) {
            if (stk.empty() || pref[stk.back()] >= pref[i]) {
                stk.push_back(i);
            }
        }
        
        for (int i = n; i >= 0; i--) {
            while (!stk.empty() && pref[i] > pref[stk.back()]) {
                ans = max(ans, i - stk.back());
                stk.pop_back();
            }
        }
        return ans;
    }
};
