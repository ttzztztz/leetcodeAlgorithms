class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(125, 0);
        for (int age : ages) cnt[age]++;

        int ans = 0;
        for (int age1 = 1; age1 <= 120; age1++) for (int age2 = 1; age2 <= 120; age2++) {
            if ((age2 <= 0.5 * age1 + 7) || (age2 > age1) || (age2 > 100 && age1 < 100)) {
                continue;
            }

            if (age1 == age2) {
                ans += cnt[age1] * (cnt[age1] - 1);
            } else {
                ans += cnt[age1] * cnt[age2];
            }
        }
        return ans;
    }
};