// special case ["a", ""]

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        
        const int n = words.size();
        unordered_map<string, int> all;
        for (int j = 0; j < n; j++) all[words[j]] = j;
        for (int j = 0; j < n; j++) {
            const string& word = words[j];
            const int m = word.size();
            
            string rev_word = word;
            reverse(rev_word.begin(), rev_word.end());
            if (all.count(rev_word) && j != all[rev_word]) {
                ans.push_back({ j, all[rev_word] });
            }
            
            string t;
            for (int i = 0; i <= m - 1; i++) {
                t += word[i];
                string rev_right = word.substr(i + 1);
                reverse(rev_right.begin(), rev_right.end());
                
                if (is_palindrome(t) && all.count(rev_right) && j != all[rev_right]) {
                    ans.push_back({ all[rev_right], j });
                }
            }
            
            t.clear();
            for (int i = m - 1; i >= 0; i--) {
                t = word[i] + t;
                string rev_left = word.substr(0, i);
                reverse(rev_left.begin(), rev_left.end());
                
                if (is_palindrome(t) && all.count(rev_left) && j != all[rev_left]) {
                    ans.push_back({ j, all[rev_left] });
                }
            }
        }
        return ans;
    }
private:
    bool is_palindrome(const string& str) {
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};