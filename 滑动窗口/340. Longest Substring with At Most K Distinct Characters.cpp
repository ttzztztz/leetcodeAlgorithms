class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        int ans = 0;
        unordered_map<char, int> appear;
        for (int l = 0, r = 0; r < s.size(); r++) {
            appear[s[r]]++;
            while (l < r && appear.size() > k) {
                appear[s[l]]--;
                if (appear[s[l]] == 0) {
                    appear.erase(s[l]);
                }
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
