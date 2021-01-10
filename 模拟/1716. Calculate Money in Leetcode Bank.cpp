class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        for (int i = 1, week = 0, last = 0, last_week = 0; i <= n; i++, week = (week + 1) % 7) {
            if (week == 0) {
                last_week++;
                last = last_week;
                ans += last;
            } else {
                last++;
                ans += last;
            }
        }
        return ans;
    }
};
