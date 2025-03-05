class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        const int sum = accumulate(weights.begin(), weights.end(), 0);

        int l = *max_element(weights.begin(), weights.end()), r = sum;
        // [> > = = < <]
        while (l <= r) {
            const int mid = (l + r) / 2;

            if (transport(weights, mid) <= days) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    int transport(const vector<int>& weights, int capacity) {
        const int n = weights.size();

        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (cur + weights[i] > capacity) {
                cur = weights[i];
                ans++;
            } else {
                cur += weights[i];
            }
        }

        if (cur > 0) ans++;
        return ans;
    }
};