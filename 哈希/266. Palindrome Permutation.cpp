class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        
        bool single = false;
        for (auto [k, v] : appear) {
            if (v % 2 == 1) {
                if (single) return false;
                else single = true;
            }
        }
        return true;
    }
};
