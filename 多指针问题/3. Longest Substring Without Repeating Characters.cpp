class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> cnt;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            while (has_duplicate(cnt)) {
                cnt[s[l]]--;
                if (cnt[s[l]] == 0) {
                    cnt.erase(s[l]);
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
private:
    bool has_duplicate(unordered_map<char, int>& hmap) {
        for (auto [k, v] : hmap) {
            if (v >= 2) return true;
        }
        return false;
    }
};