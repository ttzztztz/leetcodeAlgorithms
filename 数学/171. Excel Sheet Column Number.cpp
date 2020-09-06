class Solution {
public:
    int titleToNumber(string& s) {
        if (s.empty()) return 0;
        unordered_map<char, int> ref;
        for (char ch = 'A'; ch <= 'Z'; ch++) ref[ch] = ch - 'A' + 1;
        
        const int f = ref[s.back()];
        s.pop_back();
        
        return f + 26 * titleToNumber(s);
    }
};
