class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l <= r) {
            const int mid = (l + r) / 2;

            if (solve(weights, mid) <= days) {
                r = mid - 1;
            } else { // > days
                l = mid + 1;
            }
        }

        return l;
    }
private:
    int solve(const vector<int>& weights, int capacity) {
        int ans = 0, cur = 0;
        for (int w : weights) {
            if (cur + w > capacity) {
                cur = 0;
                ans++;
            }

            cur += w;
        }
        return ans + (cur > 0);
    }
};