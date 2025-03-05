class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();

        vector<int> l(n, 0), r(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0 || ratings[i - 1] >= ratings[i]) l[i] = 1;
            else l[i] = l[i - 1] + 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || ratings[i] <= ratings[i + 1]) r[i] = 1;
            else r[i] = r[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
        return ans;
    }
};