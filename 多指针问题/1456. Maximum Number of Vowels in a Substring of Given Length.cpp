class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        
        const int n = s.size();
        unordered_map<char, int> appear;
        
        auto calc = [&]() -> int {
            return appear['a'] + appear['e'] + appear['i'] + appear['o'] + appear['u'];
        };
        
        for (int l = 0, r = 0; r < n; r++) {
            appear[s[r]]++;
            ans = max(ans, calc());
            if (r - l + 1 == k) {
                appear[s[l]]--;
                l++;
            }
        }
        
        return ans;
    }
};