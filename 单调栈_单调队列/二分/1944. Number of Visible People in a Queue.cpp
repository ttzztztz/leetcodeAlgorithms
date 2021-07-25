class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans(n), stk, maxh(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] > heights[stk.back()]) stk.pop_back();
            if (!stk.empty()) {
                ans[i]++;
                maxh[i] = stk.back();
            }
            stk.push_back(i);
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            const int t = maxh[i];
            if (t == -1) {
                ans[i] += stk.size();
            } else {
                auto it = search(stk, t);
                ans[i] += stk.size() - it - 1;
            }

            while (!stk.empty() && heights[i] > heights[stk.back()]) stk.pop_back();
            stk.push_back(i);
        }
        
        return ans;
    }
private:
    int search(const vector<int>& stk, int target) {
        int l = 0, r = stk.size() - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;
            if (stk[mid] < target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};