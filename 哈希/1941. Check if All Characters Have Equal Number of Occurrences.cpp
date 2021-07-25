class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> a;
        for (const char ch : s) a[ch]++;
        
        int last = -1;
        for (auto& [k, v] : a) {
            if (last != -1) {
                if (last != v) return false;
            }
            last = v;
        }
        return true;
    }
};