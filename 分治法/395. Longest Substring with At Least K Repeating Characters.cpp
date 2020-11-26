class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;
        
        const int n = s.size();
        unordered_map<char, int> f;
        for (const char ch : s) f[ch]++;
        
        int mi = n + 1;
        char mi_c = 'a';
        for (auto [ch, p] : f) {
            if (p < mi) {
                mi = p;
                mi_c = ch;
            }
        }
        
        if (mi >= k) return n;
        else {
            string tmp;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == mi_c) {
                    if (!tmp.empty()) ans = max(ans, longestSubstring(tmp, k));
                    tmp.clear();
                } else tmp += s[i];
            }
            
            if (!tmp.empty()) ans = max(ans, longestSubstring(tmp, k));
            return ans;
        }
    }
};
