class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        unordered_map<char, int> cnt;
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            cnt[s[r]]++;

            while (replace_cnt(cnt) > k) {
                cnt[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
private:
    int replace_cnt(unordered_map<char, int>& cnt) {
        int sum = 0, majority_sum = 0;
        for (auto& [k, v] : cnt) {
            majority_sum = max(majority_sum, v);
            sum += v;
        }
        return sum - majority_sum;
    }
};