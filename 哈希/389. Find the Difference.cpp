class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> a1, a2;
        for (const char ch : s) a1[ch]++;
        for (const char ch : t) a2[ch]++;
        
        for (auto& p : a2) {
            char ch;
            int app;
            tie(ch, app) = p;
            
            if (a1[ch] + 1 == app) return ch;
        }
        
        return '\0';
    }
};
