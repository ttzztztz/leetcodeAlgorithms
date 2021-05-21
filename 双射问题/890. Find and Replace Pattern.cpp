class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        const int n = words.size(), m = pattern.size();
        for (int i = 0; i < n; i++) {
            if (match(words[i], pattern)) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
private:
    bool match(const string& word, const string& pattern) {
        unordered_map<char, char> f;
        for (int i = 0; i < word.size(); i++) {
            const char ch = word[i];
            if (f.count(ch) && f[ch] != pattern[i]) return false;
            f[ch] = pattern[i];
        }
        return true;
    }
};