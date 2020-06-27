class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a1, a2;
        for (const char ch : s) a1[ch]++;
        for (const char ch : t) a2[ch]++;
        return a1 == a2;
    }
};
