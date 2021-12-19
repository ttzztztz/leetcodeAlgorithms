class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& word : words) {
            if (is_palindrome(word)) return word;
        }
        return "";
    }
private:
    bool is_palindrome(const string& word) {
        for (int l = 0, r = word.size() - 1; l < r; l++, r--) {
            if (word[l] != word[r]) return false;
        }
        return true;
    }
};
