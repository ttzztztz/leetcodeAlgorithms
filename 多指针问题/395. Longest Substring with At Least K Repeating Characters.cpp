class Solution {
public:
    int longestSubstring(string s, int k) {
        const int n = s.size();
        int ans = 0;
        for (int len = 1; len <= 26; len++) {
            unordered_map<char, int> f;
            
            auto ok = [&]() -> bool {
                for (auto [ch, p] : f) {
                    if (p < k) return false;
                }
                return true;
            };
            
            for (int l = 0, r = 0; r < n; r++) {
                f[s[r]]++;
                while (f.size() > len) {
                    f[s[l]]--;
                    if (f[s[l]] == 0) f.erase(s[l]);
                    
                    l++;
                }
                
                if (ok()) ans = max(ans, r - l + 1);
            }
        }
        
        return ans;
    }
};
