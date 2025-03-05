class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        typedef long long ll;
        ll ans = 0;

        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            const int val = i - nums[i];

            int same = 0;
            if (cnt.count(val)) same = cnt[val];
            ans += i - same;

            cnt[val]++;
        }
        return ans;
    }
};