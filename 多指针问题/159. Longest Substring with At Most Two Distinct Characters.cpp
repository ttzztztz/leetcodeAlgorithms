class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        unordered_map<int, int> appear;
        for (int l = 0, r = 0; r < s.size(); r++) {
            appear[s[r]]++;
            while (l < r && appear.size() > 2) {
                appear[s[l]]--;
                if (appear[s[l]] == 0) appear.erase(s[l]);
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
