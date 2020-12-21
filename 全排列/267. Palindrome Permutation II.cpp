class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the palindromic permutations (without duplicates) of it
     */
    vector<string> generatePalindromes(string &s) {
        vector<string> answer;
        
        const int N = s.size();
        char middle = '\0';
        
        vector<int> appear(26, 0);
        for (char ch : s) {
            appear[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            int& cnt = appear[i];
            if (cnt % 2 == 0) continue;
            
            if (N % 2 == 1) {
                if (middle == '\0') {
                    middle = 'a' + i;
                } else {
                    return answer;
                }
            } else {
                return answer;
            }
        }
        
        string prefix;
        for (int i = 0; i < 26; i++) {
            string current(appear[i] / 2, 'a' + i);
            prefix += current;
        }
        
        unordered_set<string> temp;
        do {
            string current;
            
            string reversed_prefix = prefix;
            reverse(reversed_prefix.begin(), reversed_prefix.end());
            
            current += prefix;
            if (N % 2 == 1) current += middle;
            current += reversed_prefix;
            
            temp.insert(current);
        } while (next_permutation(prefix.begin(), prefix.end()));
        
        answer = vector<string>(temp.begin(), temp.end());
        return answer;
    }
};
