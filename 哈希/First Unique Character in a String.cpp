class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        
        for (int i = 0; i < s.size(); i++) {
            if (appear[s[i]] == 1) return i;
         }
        return -1;
    }
};
