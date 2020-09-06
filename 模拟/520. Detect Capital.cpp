class Solution {
public:
    bool detectCapitalUse(string word) {
        const bool first = word[0] >= 'A' && word[0] <= 'Z';
        
        for (int i = 1; i < word.size(); i++) {
            if (!first) {
                if (!(word[i] >= 'a' && word[i] <= 'z')) return false;
            } else {
                if (i >= 2) {
                    const bool x = word[1] >= 'A' && word[1] <= 'Z';
                    const bool isUpper = word[i] >= 'A' && word[i] <= 'Z';
                    
                    if (isUpper && !x) return false;
                    if (x && !isUpper) return false;
                }
            }
        }
        
        return true;
    }
};
