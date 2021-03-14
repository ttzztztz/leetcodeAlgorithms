class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        unordered_map<char, int> a, b;
        for (const char ch : s1) a[ch]++;
        for (const char ch : s2) b[ch]++;
        if (a != b) return false;
        
        const int n = s1.size();
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff++;
                
                if (diff > 2) return false;
            }
        }
        return true;
    }
};
