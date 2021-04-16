class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> occur;
        unordered_map<char, int> letter;
        int ans = 0;
        
        for (int i = 0; i < minSize; i++) letter[s[i]]++;
        if (letter.size() <= maxLetters) ans = max(ans, ++occur[s.substr(0, minSize)]);
        for (int l = 0, r = minSize; r < s.size(); l++, r++) {
            letter[s[r]]++;
            letter[s[l]]--;
            if (letter[s[l]] == 0) letter.erase(s[l]);
            
            if (letter.size() <= maxLetters) ans = max(ans, ++occur[s.substr(l + 1, minSize)]);
        }
        return ans;
    }
};