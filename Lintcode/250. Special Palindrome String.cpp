class Solution {
public:
    /**
     * @param ambigram: A list of paired ambigram letter.
     * @param word: A string need to be judged.
     * @return: If it is special palindrome string, return true.
     */
    bool ispalindrome(vector<string> &ambigram, string &word) {
        unordered_map<char, vector<char>> memo;
        for (const auto& p : ambigram) {
            memo[p[0]].push_back(p[1]);
            memo[p[1]].push_back(p[0]);
        }
        
        int left = 0, right = word.size() - 1;
        while (left < right) {
            if (word[left] == word[right]) {
                left++, right--;
                continue;
            }
            
            
            bool ok = false;
            for (char ch1 : memo[word[left]]) {
                for (char ch2: memo[word[right]]) {
                    if (ch1 == ch2 || ch1 == word[right] || ch2 == word[left]) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (!ok) {
                return false;
            }
            left++, right--;
        }
        return true;
    }
};
