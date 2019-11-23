class Solution {
public:
    unordered_map<char, int> charList;
    unordered_set<char> charSet;
    
    string minWindow(string s, string t) {
        for (const char& ch : t) {
            charList[ch]++;
            charSet.insert(ch);
        }
        int needMatch = charSet.size();

        const int T = t.size(), S = s.size();
        int left = 0, right = 0, minLen = 99999999, answerLeft = -1;
        
        unordered_map<char, int> windowChar = charList;
        // init window
        for (right = 0; right < T; right++) {
            if (charSet.count(s[right])) {
                windowChar[s[right]]--;
                if (windowChar[s[right]] == 0) {
                    needMatch--;
                }
            }
        }
        right--;
        
        while (right <= S) {
            const bool valid = needMatch == 0;
            if (valid) {
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    answerLeft = left;
                }
                
                if (charSet.count(s[left])) {
                    windowChar[s[left]]++;
                    if (windowChar[s[left]] > 0) {
                        needMatch++;
                    }
                }
                
                left++;
            } else {
                right++;
                if (right < S && charSet.count(s[right])) {
                    windowChar[s[right]]--;
                    if (windowChar[s[right]] == 0) {
                        needMatch--;
                    }
                }
            }
        }
        
        if (answerLeft == -1) {
            return "";
        } else {
            return s.substr(answerLeft, minLen);
        }
    }
};